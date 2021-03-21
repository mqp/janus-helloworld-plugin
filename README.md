# Janus "hello world" plugin

It was a big pain in the butt to figure out how to independently build [plugins][] and [event handlers][] for [Janus][] outside of the Janus repository build scripts, so here is a skeleton for building them using autotools.

The plugins/ directory contains a simple plugin, and the events/ directory contains a simple event handler. You can build them both with `make` at the top level, or build them individually in their respective directories.

**The samples given are compatible with an old version of Janus (0.4.3). They will likely require modification to work correctly with newer versions.** However, the build process and general plugin structure AFAIK has stayed the same.

``` shell
./bootstrap
./configure --prefix=/opt/janus  # or wherever your janus install lives
make
make install  # installs into /opt/janus/lib/janus/plugins and /opt/janus/lib/janus/events
```

[Janus]: https://github.com/meetecho/janus-gateway
[plugins]: https://janus.conf.meetecho.com/docs/group__plugins.html
[event handlers]: https://janus.conf.meetecho.com/docs/group__eventhandlerapi.html
[version 0.2.6]: https://launchpad.net/ubuntu/+source/janus
