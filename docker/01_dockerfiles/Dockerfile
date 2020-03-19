FROM debian:9.7

RUN apt-get update \
&& apt-get upgrade -y \
&& apt-get install -y curl openssh-server ca-certificates \
&& curl -sS \
https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh \
| bash \
&& apt-get install -y gitlab.ce 

#ENTRYPOINT (./opt/gitlab/embedded/bin/runsvdir-start &) \
#&& gitlab-ctl reconfigure \
#&& gitlab-ctl tail

# maybe needed to do the next line
# chmod 777 /opt/gitlab/embedded/etc/90-omnibus-gitlab-kernel.shmmax.conf
# chmod 777 /opt/gitlab/embedded/etc/90-omnibus-gitlab-kernel.shmall.conf
# or maybe change the /etc/sysctl.conf files rights
################
# The fix is to set them manually on the host. 
# You should be able to find the values we want  
# at: /opt/gitlab/embedded/etc/90-omnibus-gitlab.conf 
# (once you've run reconfigure and hit this error)
# Set these values in /etc/sysctl.conf on the host,
#  and run cat /etc/sysctl.conf /etc/sysctl.d/*.conf  | sysctl -e -p - on the host.
# Then run reconfigure in your lxc container again, 
# it should detect that the kernel is already running with the necessary settings, 
# and not make any changes.