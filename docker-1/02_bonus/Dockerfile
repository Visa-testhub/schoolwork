FROM debian

EXPOSE 25565

RUN apt-get update -y \
&& apt-get upgrade -y \
&& apt-get install -y default-jdk screen wget

RUN wget https://launcher.mojang.com/v1/objects/bb2b6b1aefcd70dfd1892149ac3a215f6c636b07/server.jar \
&& java -Xmx1024M -Xms1024M -jar server.jar nogui \
&& sed -i -e s/eula=false/eula=true/g eula.txt 

ENTRYPOINT java -Xmx1024M -Xms1024M -jar server.jar nogui

# docker build -t mcserver .
# docker run -d -it -p 25565:25565 --name mc mcserver
# to pause server, use
# docker exec stop mc
# to join server, go to multiplayer, direct connect and add the $(docker-machine ip) there.
# if you are using another port than 25565, you need to specify that.
