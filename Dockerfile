FROM    debian:buster

RUN            set -eux; \
            apt-get update && apt-get install -y \
                clang \
                gcc \
                git \
                make \
                procps \
                tree \
                valgrind \
                vim \
            && apt-get clean