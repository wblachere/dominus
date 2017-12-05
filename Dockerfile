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

RUN wget https://buildroot.org/downloads/buildroot-2017.08.tar.gz
RUN tar zxvf buildroot-2017.08.tar.gz
RUN make raspberrypi3_defconfig
RUN make

WORKDIR /root

CMD ["bin/bash"]
