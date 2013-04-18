if [ ! -e ~/.ssh/authorized_keys ]; then
    if [ ! -e ~/.ssh/id_dsa.pub ]; then
	ssh-keygen -t dsa -f ~/.ssh/id_dsa -N ''
    fi
    cp ~/.ssh/id_dsa.pub ~/.ssh/authorized_keys 
    chmod 600 ~/.ssh/authorized_keys
    # Workaround for issue with PBS trying to scp output back to
    # peregrine.hpc.uwm.edu and getting prompted to add host
    ssh peregrine ls > /dev/null
fi

