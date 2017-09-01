[![Build Status](https://travis-ci.org/jonathanbell/PhotogSite.svg?branch=master)](https://travis-ci.org/jonathanbell/PhotogSite)

# PhotogSite

PhotogSite creates a portfolio website for photographers and artists. Simply, size your images and place them into folders - PhotogSite will produce a website [like this one](http://jonathanbell.ca/).

Each sub-folder inside PhotogSite's ```_sections``` folder becomes a section on your website. Simply create folders and place each section's images inside them. The folder names become the titles of each portfolio section on your site.

PhotogSite was written with simplicity in mind. There are no databases, no install files, no login screen, no admin interface - just a simple way to stand up an artist's portfolio site quickly.

## Installation

1. [Download](https://github.com/jonathanbell/PhotogSite/archive/master.zip) or clone this repository.
1. In preparation for upload, size your images in a photo editor like PhotoShop. Make your images ~1000px tall. **Save your images as "optimized for web"** otherwise they will load slowly over the internet. You may also wish to use an image squisher, such as [ImageOptim](https://imageoptim.com/versions.html) or [Trimage](https://trimage.org/). Do not use ImageOptim or Trimage if you wish to preserve your [image captions](https://github.com/jonathanbell/PhotogSite#captions).
1. Copy and rename ```demo.config.ini``` to ```config.ini```.
1. Open ```config.ini``` inside your text editor and adjust the values to suite your needs. Change ```demo_mode``` from ```true``` to ```false```. Values can be ```true``` or ```false``` or a string inside "quotes" such as ```"myemail@email.com"```. Do not remove "quotes" and do not add quote marks to the file. Edit the values as ```true``` or ```false``` or change the values inside the "quotes". The values inside ```config.ini``` are used to customize your site. See the [configuration options](https://github.com/jonathanbell/PhotogSite#options) for more information.
1. Inside the ```_sections``` folder, create a folder for each section of your site. Title each folder with the name of its section. For example, you might make 3 folders titled: "portraits", "still life" and "personal work". **Do not use capital letters.** PhotogSite's default theme displays the section names capitalized in the main navigation area of your site. To adjust the display order of each section, see: [Display Order](https://github.com/jonathanbell/PhotogSite#display-order-and-naming-conventions)
1. Upload/move the images for each section into their proper folders on your site. For example, if you were following the example above, you would place all of your personal work into the "_personal work_" folder and all of your portrait work into the "_portraits_" folder.
1. Upload all of the code files and images to your web server, if you haven't already done so.
1. You're done! Go checkout your new site!

For more information, or, if you need help you can view [the (slightly outdated) installation video](https://www.youtube.com/watch?v=xnd18UwaMWs) or [email me](mailto:jonathanbell.ca@gmail.com).

## Requirements

Almost all commercial webhosts will meet PhotogSite's requirements. A basic install requires:

- Apache2 (or Nginx, see below)
- PHP version 5.3 or greater
- Correct file permissions (775) for PHP to create and delete files inside the PhotogSite root directory and subdirectories

### Using Nginx?

Add these lines to your Nginx `server` block for PhotogSite to perform proper URL rewrites.

```
server {

  ...

  location ~ \.php$ {
    # Pass a request for a PHP file to your PHP installation.
    ...
  }

  location / {
    try_files $uri $uri/ @fallback;
  }

  location @fallback {
    rewrite ^/(.*)$ /index.php?section=$1 last;
  }

  ...

}
```

### Installing Photogsite to a Non-root Path

If you would like to install Photogsite to a path other than your root domain (ie. `mysite.com` vs `mysite.com/photogsite`), you'll need to edit your `.htaccess` file (for Apache) or site's configuration file (for Nginx).

#### Instructions for Apache Web Server

1. Find the line `RewriteBase /` (around line 130) in the `.htaccess` file.
1. Comment out (add a "`#`" at the beginning of the line or remove the line) `RewriteBase /`
1. Comment in (remove the "`#`" at the front of the line) `RewriteBase /photogsite/`
1. Replace "`photogsite`" with the actual path to your Photogsite installation. For example: `RewriteBase /my-photos/`

You're done. Do not edit other values inside the `.htaccess` file.

## Browser Support

Currently Photogsite works (and displays well) in all modern mobile and desktop browsers including Internet Explorer version 11 and MS Edge. The default responsive theme allows easy viewing on mobile devices.

## Options

PhotogSite has a number of user configurable options.

### Display Order and Naming Conventions
You can easily change the display order of your portfolio's sections. For example, you might have a portfolio section called "zebras" and one called "apple". Normally, "apple" will display before "zebra". However, by adding **01_** to "zebra" and adding **02\_** to "apple" we can display "zebra" before "apple" in the navigation.

This naming convention is optional. Folder names **01_zebras** and **zebras** are both valid.

If you do want to change the display order of your portfolio's sections, simply follow the folder naming convention: **01_**zebras, **02\_**apples, **03\_**portraits, etc.

### config.ini
By default, PhotogSite will look for a ```config.ini``` file inside the PhotogSite root directory. This file contains most of PhotogSite's options and their values. The ```config.ini``` options follow the convention: ```option = "value" | [true|false]```

To change one of the options on your site, simply edit the ```config.ini``` file using a text editor.

- **demo\_mode** _boolean_
By default, if you don't copy and rename ```demo.config.ini``` demo mode will be used. PhotogSite will show the demo images (animals) instead of the content inside the ```_sections``` directory.

- **site\_title** _string_
The title of your site or your name.

- **show\_site\_title** _boolean_
Show or hide the site title in the main navigation bar.

- **email\_address** _string_
Your email address. Only shown if **show\_contact\_link** is ```true```

- **blog\_url** _string_
The URL of your blog (in case you'd like to link to your blog from your website). Example: ```"http://myblog.com"``` Only shown if **show\_blog\_link** is set to ```true```

- **blog\_title** _string_
The text displayed as the link to your blog. Example: ```"My Blog"```

- **show\_blog\_link** _boolean_
Should we show the link to your blog or hide it?

- **promote\_photogsite** _boolean_
Shows "Site created with PhotogSite" at the bottom of the main navigation. If you were nice, you'd leave this set to ```true```

- **show\_copywrite** _boolean_
Displays "Copywrite {year} {site_title}" at the bottom of the main navigation.

- **show\_random\_homepage\_image** _boolean_
Displays one of your portfolio images at random on the homepage.

- **google\_ua\_code** _string_
If you have a Google Analytics [tracking code](https://support.google.com/analytics/answer/1032385?hl=en), paste it here and set **use\_google\_analytics** to ```true```

- **use\_google\_analytics** _boolean_
Only enable if you are using [Google Analytics](https://www.google.com/analytics) on your site.

### logo.png
If you would like to display your logo on your portfolio site, simply place a file named ```logo.png``` inside PhotogSite's root directory. It's recommened to upload a logo with a transparent background.

### favicon.ico
Similar to logo.png, simply place a 16px X 16px ```favicon.ico``` file at the root of your PhotogSite install. You can also place a apple-touch-icon.png at the root of your site.

### Captions
PhotogSite will automagically detect the presence of captions contained within the metadata of each photo and display the caption if it finds one. To add captions to your images, open them in your favourite image editor and edit the image's "Description" metadata. Boom! Instant caption!

### Intro Text
If you'd like to display some introductory text at the beginning of a section, place a file named ```intro.html``` alongside your images inside the section's folder. The introductory text will display at the begining of the portfolio section. Note that you should use HTML to write this file. You can find an example in ```_demo.sections/03_bears/intro.html```. Simply copy this file into your own section and edit its contents with your text editor.

### Adding Links and Content to the Sidebar
You can add content such as links and short paragraphs into the main navigation. Simply copy and rename ```demo.additional_links.html``` to ```additional_links.html``` inside PhotogSite's root directory. Open ```additional_links.html``` in your text editor and follow the instructions contained within. Some basic knowledge of HTML is required to edit this file.

### Videos
Videos are not yet supported but YouTube & Vimeo videos will be supported in a future release.

## Theming

Currently, theming support is simple and basic.

1. Copy and rename the file `demo.user.css` to `user.css` inside the `/css` folder.
1. Write your own styles (overwriting Photogsite's default theme) inside the file that you just copied (`user.css`).

The above method will overwrite the CSS for the Photogsite default theme. If you want to write your own CSS from scratch, you can - just add your CSS files to the `/css` folder and Photogsite will concatenate them and output the CSS to the webpage.

## PhotogSite was Inspired by:
- [Stacey](http://www.staceyapp.com/)
- [Jonathan Waiter](http://www.jonathanwaiter.com/)
- [Cass Bird](http://www.cassbird.com/)
- [Indexhibit](http://www.indexhibit.org/)
- And my own personal need to have a super simple portfolio website that I can update easily! Life's too short to spend it updating your website - go shoot some pictures instead!

## Support

Please [file an issue](https://github.com/jonathanbell/PhotogSite/issues) if you encounter any errors.

![It's free software](https://camo.githubusercontent.com/df781f87da2f2db87b5cc3125d5459bc70812112/687474703a2f2f64726f70732e6b796c65666f782e63612f31637147502b)

Thanks.
