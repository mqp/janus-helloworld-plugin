# Janus "hello world" plugin

It was a big pain in the butt to figure out how to independently build a plugin for [Janus] outside of the Janus repository build scripts, so here is a skeleton for building one using autotools.

To build:

``` shell
./bootstrap
./configure --prefix=/opt/janus  # or wherever your janus install lives
make
make install  # builds into /opt/janus/lib/janus/plugins
```

[Janus]: https://github.com/meetecho/janus-gateway
