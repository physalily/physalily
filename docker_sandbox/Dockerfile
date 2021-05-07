# based image
FROM centos
# user info
MAINTAINER physalily <physalily@gmail.com>

# RUN: executed in "docker build"
# RUN echo "now building..."
# CMD: executed in "docker run"
CMD echo "now running..."

# install httpd
RUN yum install -y httpd
# copy index.html in host to docker image.
ADD ./index.html /var/www/html/
# open port 80
EXPOSE 80
# launch appache when docker run
CMD ["/usr/sbin/httpd", "-D", "FOREGROUND"]

