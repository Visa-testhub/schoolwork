
From debian:9.7

MAINTAINER Visa Keinänen vkeinanen@student.hive.fi

ENV TS3SERVER_LICENSE=accept

EXPOSE 9987/udp 30033 10011

RUN apt-get update && \
apt-get upgrade -y && \
apt-get -y install wget bzip2 && \
wget https://files.teamspeak-services.com/releases/server/3.11.0/teamspeak3-server_linux_amd64-3.11.0.tar.bz2 && \
tar -xvjf teamspeak3-server_linux_amd64-3.11.0.tar.bz2 && \
rm teamspeak3-server_linux_amd64-3.11.0.tar.bz2 && \
mkdir /opt/teamspeak-server && \
mv teamspeak3-server_linux_amd64/* /opt/teamspeak-server && \
cd /opt/teamspeak-server && \
useradd -d /opt/teamspeak-server teamspeak-user && \
chown -R teamspeak-user:teamspeak-user /opt/teamspeak-server

WORKDIR /opt/teamspeak-server

ENTRYPOINT ./ts3server_minimal_runscript.sh
#to test, use these
#docker build -t teamspeak .
#docker run -d --restart=always --name teamspeak -p 9987:9987/udp -p 30033:30033 -p 10011:10011  teamspeak
#copy the docker-mahcine ip Char
#open teamspeak client and connect to it with ip
#docker logs teamspeak
#copy the token from the logs
#use the token when connecting to the teamspeak server to get admin rights
