# workaround for partnerid 
insert_partner_id(){
    mkdir -p ${IMAGE_ROOTFS}/opt/www/authService
    if [ ! -f "${IMAGE_ROOTFS}/opt/www/authService/partnerId3.dat" ]; then
        touch ${IMAGE_ROOTFS}/opt/www/authService/partnerId3.dat
        echo "community" > ${IMAGE_ROOTFS}/opt/www/authService/partnerId3.dat
    fi
}

# workaround for bsp complete.ini path
handle_bsp_complete(){
 if [ ! -f "${IMAGE_ROOTFS}/opt/bspcomplete.ini" ]; then
    touch ${IMAGE_ROOTFS}/opt/bspcomplete.ini
 fi

}

ROOTFS_POSTPROCESS_COMMAND += "insert_partner_id; handle_bsp_complete; "

