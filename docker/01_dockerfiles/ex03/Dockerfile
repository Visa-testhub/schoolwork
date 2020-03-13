FROM debian:9.7

EXPOSE 80 443
RUN apt-get update \
&& apt-get upgrade -y \
&& apt-get install -y curl openssh-server ca-certificates openssl
RUN curl -sS https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | bash
RUN apt-get install gitlab-ce
#RUN EXTERNAL_URL="https://gitlab.example.com" apt-get install gitlab-ce




#RUN echo "external_url /"https:gitlab.example.com/"" >> /etc/gitlab/gitlab.rb
#RUN apt-get install -y gitlab-ce
#RUN mkdir -p /etc/gitlab/ssl \
#&& openssl genrsa -out "/etc/gitlab/ssl/gitlab.key" 2048 \
#&& echo 'FI\nFinland\nHelsinki\nMyStudio\n\ngitlab.mydomain.com\nvkeinane.student@hive.fi\n\n\n' | openssl req -new -key "/etc/gitlab/ssl/gitlab.key" -out "/etc/gitlab/ssl/gitlab.csr" \
#&& openssl x509 -req -days 365 -in "/etc/nginx/ssl/gitlab.csr" -signkey "/etc/nginx/ssl/gitlab.key"  -out "/etc/nginx/ssl/gitlab.crt"
#RUN gitlab-ctl reconfigure
#ENTRYPOINT gitlab-ctl start
#RUN ufw allow WWW Full && ufw allow OpenSSH ####THISNOWORK

##################
# Run this with atleast -p 80:8080 -p 443:8443