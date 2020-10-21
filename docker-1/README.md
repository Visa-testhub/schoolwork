# Docker-1

Goal of this project is to get comfortable using docker and understanding the idea of containerization
of services.

The docker.en.pdf is the assignement and it has all the questions to my answers.
# Example

<img src="/Images/Docker-questions.png">
<img src="/Images/Docker-answers.png">

The first part (00-how-to-docker) is focused on docker and docker-machine commands,
the second part (01-Dockerfiles) focuses on dockerfiles


The requirements for executing the dockerfiles and docker commands are
docker, docker-machine and virtualbox.
Simple way to install docker and docker machine via terminal if you have Homebrew.

1. Download docker and docker-machine with brew
> rm -rf $HOME/.brew && git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew && echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc && source $HOME/.zshrc && brew update

2. Install docker and docker-machine
> brew install docker docker-machine

3. Check docker version
> docker --version

Homebrew https://github.com/Homebrew/brew
