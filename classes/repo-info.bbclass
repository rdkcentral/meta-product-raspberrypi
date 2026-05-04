python set_project_branch () {
    import subprocess, os

    dvar = d

    rdkroot = dvar.getVar('RDKROOT')
    if not rdkroot:
        return

    repo_path = os.path.join(rdkroot, ".repo/manifests")

    def run(cmd):
        try:
            return subprocess.check_output(
                cmd, shell=True, cwd=repo_path
            ).decode().strip()
        except:
            return ""

    result = ""

    # ------------------------------------------------------------
    # 1. Check exact TAG (highest priority)
    # ------------------------------------------------------------
    tag = run("git describe --tags --exact-match")
    if tag:
        result = "refs/tags/" + tag

    # ------------------------------------------------------------
    # 2. Upstream branch (best for repo)
    # ------------------------------------------------------------
    if not result:
        upstream = run("git rev-parse --abbrev-ref --symbolic-full-name @{u}")
        if upstream:
            result = upstream.replace("origin/", "")

    # ------------------------------------------------------------
    # 3. Local branch
    # ------------------------------------------------------------
    if not result:
        branch = run("git symbolic-ref -q --short HEAD")
        if branch and branch != "HEAD":
            result = branch

    # ------------------------------------------------------------
    # 4. Remote branch containing HEAD (fallback)
    # ------------------------------------------------------------
    if not result:
        remote = run("git branch -r --contains HEAD | grep -v HEAD | head -n1")
        if remote:
            result = remote.strip().replace("origin/", "")

    # ------------------------------------------------------------
    # 5. Final fallback
    # ------------------------------------------------------------
    if not result:
        commit = run("git rev-parse --short HEAD")
        result = "detached-" + commit

    # ------------------------------------------------------------
    # Set variable
    # ------------------------------------------------------------
    dvar.setVar("PROJECT_BRANCH", result)

    bb.note("FINAL PROJECT_BRANCH = %s" % result)
}

ROOTFS_PREPROCESS_COMMAND += " set_project_branch; "
