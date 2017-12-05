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
	nano \
	ncurses-dev \
	python \
	wget

WORKDIR /root

RUN wget https://buildroot.org/downloads/buildroot-2017.08.tar.gz
RUN tar zxvf buildroot-2017.08.tar.gz

WORKDIR /root/buildroot-2017.08

RUN make raspberrypi3_defconfig
RUN wget https://github.com/TilletJ/dominus/tree/dockerfile/.config
RUN make

CMD ["bin/bash"]
