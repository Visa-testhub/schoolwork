FROM ruby:2.7

RUN curl -sS https://dl.yarnpkg.com/debian/pubkey.gpg | apt-key add - \
&&	echo "deb https://dl.yarnpkg.com/debian/ stable main" | tee /etc/apt/sources.list.d/yarn.list \
&&	apt-get update \
&&	apt-get upgrade -y \
&&	apt-get install -y nodejs yarn build-essential \
&&	gem install bundler
CMD mkdir /opt/app 

ONBUILD WORKDIR /opt/app
ONBUILD COPY ./test_app /opt/app
ONBUILD RUN cd app \
&& bundle update --bundler \
&& bundle install \
&& yarn install --check-files \
&& bundle exec rake db:migrate \
&& bundle exec rake db:seed

# To build this use 
# docker build -t ft-rails:on-build .
# Go to tmp directory
# Build the rest in tmp directory, with
# docker build -t rubyit .
# docker run -d -p 3000:3000 rubyit
# open the appropriate website.
# the website should be your ip and port 3000 like this 192.168.99.100:3000
# or you can find the ip with "docker-machine ip Char"
# remember to put the :3000 behind the ip.
# you can login to the sample app with EMAIL example@railstutorial.org and PASSWORD foobar
# all glory from the rails app to Michael Hartl (mhartl) in Github.
