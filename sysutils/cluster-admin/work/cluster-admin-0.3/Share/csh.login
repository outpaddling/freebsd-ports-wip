if ( ! -e ~/.ssh/authorized_keys ) then
    if ( ! -e ~/.ssh/id_dsa.pub ) then
	ssh-keygen -t dsa -f ~/.ssh/id_dsa -N ''
    endif
    cp ~/.ssh/id_dsa.pub ~/.ssh/authorized_keys 
    chmod 600 ~/.ssh/authorized_keys
endif

