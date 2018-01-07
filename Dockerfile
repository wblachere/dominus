FROM debian:stable

RUN apt-get update && apt-get install -y \
	bc \
	bzip2 \
	cpio \
	file \
	gcc \
	g++ \
	git \
	gzip \
	make \
	ncurses-dev \
	python \
	unzip \
	wget

WORKDIR /root

COPY buildroot-2017.08.tar.gz https://buildroot.org/downloads/buildroot-2017.08.tar.gz
RUN tar zxvf buildroot-2017.08.tar.gz
COPY users.tables https://github.com/TilletJ/dominus/tree/dockerfile/users.tables

WORKDIR /root/buildroot-2017.08

RUN make raspberrypi3_defconfig
COPY .config https://github.com/TilletJ/dominus/tree/dockerfile/.config
RUN git config --global http.postBuffer 1048576000
RUN make

CMD ["/bin/bash"]
