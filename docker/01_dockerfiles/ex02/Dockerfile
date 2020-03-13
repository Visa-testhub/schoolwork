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
# docker build -t ft-rails:on-build /Users/vkeinane/docker/01_dockerfiles/ex02/
# Then make tmp directory
# cd tmp
# Then get the dockerfile from the subject and copy it to tmp
# This build requires app to be in the same directory as the dockerfile for onbuild
# git clone https://github.com/mhartl/sample_app_6th_ed test_app
# Clone that to tmp directory and then build the rest with
# docker build -t rubyit /Users/vkeinane/docker/01_dockerfiles/ex02/tmp/
# docker run -d -p 3000:3000 rubyit
# open the appropriate website. usually it is 192.168.99.100:3000
# you can login to the sample app with EMAIL example@railstutorial.org and PASSWORD foobar