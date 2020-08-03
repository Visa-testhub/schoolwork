FROM debian

EXPOSE 443 22

RUN apt-get update -y \
&& apt-get upgrade -y \
&& apt-get install -y curl openssh-server ca-certificates

RUN curl -sS https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | bash \
&& apt-get install -y gitlab-ce

RUN mkdir -p /etc/gitlab/ssl \
&& chmod 755 /etc/gitlab/ssl \
&& openssl req -new -x509 -nodes -batch -newkey rsa:2048 -keyout /etc/gitlab/ssl/gitlab.key -out /etc/gitlab/ssl/gitlab.crt -days 365 \
&& echo "external_url \"https://192.168.99.100\"" >> /etc/gitlab/gitlab.rb \
&& echo "nginx['ssl_certificate'] = \"/etc/gitlab/ssl/gitlab.crt\"" >> /etc/gitlab/gitlab.rb \
&& echo "nginx['ssl_certificate_key'] = \"/etc/gitlab/ssl/gitlab.key\"" >> /etc/gitlab/gitlab.rb \
&& echo "gitlab_rails['gitlab_shell_ssh_port'] = 22" >> /etc/gitlab/gitlab.rb

ENTRYPOINT  (/opt/gitlab/embedded/bin/runsvdir-start &) \
&& service ssh start \
&& gitlab-ctl reconfigure \
&& gitlab-ctl tail

# To build and run this.
# In the same directory as the Dockerfile, do
#
# docker build -t gitlab .
# docker run --rm -it -p 8443:443 -p 8022:22 --privileged gitlab
#
# To access web client, open safari with address,
# https://192.168.99.100:8443
# Depeding on the ip docker-machine gives you, you have to change all occurances of the ip above
# Get your docker ip with "docker-machine ip (your docker-machine name here)"
#
# At the site, make a password, and login with root.
# To create users, go to the front page and add people.
# To interact with git, make a new project in gitlab.
# Generate keys and copy the bublic key to ssh-keys part on your gitlab.
#
# ssh-keygen -t ed25519 -C 'root@gitlab.com'
# pbcopy < ~/.ssh/id_ed25519.pub
# ssh -T -p 8022 git@192.168.99.100
# git clone ssh://git@192.168.99.100:8022/root/projectname.git gitlabrepo
# GIT_SSL_NO_VERIFY=true git clone https://192.168.99.100:8443/root/projectname.git gitlabrepo
