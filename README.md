# minimal-clap-plugin-c

_This repository relates to [one of my blog posts](https://tphbrok.me/blog/road-to-audio-software-developer-2)_

This repository contains whatever is needed to compile a minimal CLAP plug-in in plain C, which free-audio's `clap-info` accepts. It's made to be built on MacOS, perhaps other OSes will follow someday.

When cloning the repository, make sure to include `--recursive-submodules` to get the `clap` and `clap-info` submodules.

Afterwards, run

```sh
cd tools/clap-info && git submodule init && git submodule update
```

to fetch `clap-info`'s dependencies.

## Building and running

To compile the plug-in to a shared library (outputting it in a subfolder of the template `plugin.clap` bundle):

```sh
make build
```

To compile the plug-in and `clap-info`, and then also run `clap-info` to validate the plug-in:

```sh
make run-clap-info
```
