# Change Log

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/).

Please log issues regarding PhotogSite here: [https://github.com/jonathanbell/photogsite/issues](https://github.com/jonathanbell/photogsite/issues)

## [Unreleased]
### Added
- Support video. Most videos hosted by commercial web hosts don't play well, because poor bandwidth - so we dropped support for HTML5 video. Let's add support for YouTube.
- Start following [SemVer](http://semver.org) properly.

## [0.0.1] - 2016-12-20
### Added
- Added this CHANGELOG file to hopefully serve as an evolving example of a standardized open source project CHANGELOG.
- [Added documentation and instructions for installation](https://github.com/jonathanbell/photogsite/issues/1) in the [README](https://github.com/jonathanbell/photogsite/blob/master/README.md).

### Changed
- [Start versioning based on the new file, CHANGELOG.md](https://github.com/jonathanbell/photogsite/issues/1)
- HTML output now validates at: [https://validator.w3.org](https://validator.w3.org) :) 

### Fixed
- Weird CSS height issue on iOS on pageload.
- [Massive, *MASSIVE* code cleanup.](https://github.com/jonathanbell/photogsite/issues/2)
- [Use vh units to scale the images on "desktop" viewports.](https://github.com/jonathanbell/photogsite/issues/3)

### Removed
- Support for HTML5 Videos. Right now (v0.0.1), PhotogSite only supports still images. 
- Removed GitHub Pages website (not using this branch/service).
