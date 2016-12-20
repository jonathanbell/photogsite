[![Build Status](https://travis-ci.org/jonathanbell/photogsite.svg)](https://travis-ci.org/jonathanbell/photogsite)

PhotogSite
==========

PhotogSite creates a portfolio website for photographers and artists. Simply, size your images and place them into folders - PhotogSite will produce a website [like this one](http://jonathanbell.ca/).

Each sub-folder inside PhotogSite's ```_sections``` folder becomes a section on your website. Simply create folders and place each section's images inside them. The folder names become the titles of each portfolio section on your site. 

PhotogSite was written with simplicity in mind. There are no databases, no install files, no login screen, no admin interface - just a simple way to stand up an artist's portfolio site quickly.

## Installation

1. Download or clone this repository.
1. Copy and rename ```demo.config.ini``` to ```config.ini```.
1. Open ```config.ini``` inside your text editor and adjust the values to suite your needs. Change ```demo_mode``` from ```true``` to ```false```. Values can be ```true``` or ```false``` or a string inside "quotes" such as ```"myemail@email.com"```. Do not remove "quotes" and do not add quote marks to the file. Edit the values as ```true``` or ```false``` or change the values inside the "quotes". The values inside this file are used to customize your site. 
1. In preparation for upload, size your images in a photo editor like PhotoShop. Make your images ~1000px tall. Save the images as "optimized for web".
1. Inside the ```_sections``` folder, create a folder for each section of your site. Title each folder with the name of its section. For example, you might make 3 folders titled: "portraits", "still life" and "personal work". **Do not use capital letters.** PhotogSite's default theme will show the section names capitalized inside the main navigation of the site. 
1. Upload/place the images for each section into their proper folders on your site. Following the example above, place all of your personal work into the "personal work" folder and all of your portrait work into the "portraits" folder.
1. You're done! Go checkout your new site!

For more information, or, if you need help [the old installation video](https://www.youtube.com/watch?v=xnd18UwaMWs).

## Requirements

Almost all commercial webhosts will meet PhotogSite's requirements. A basic install requires: 

- Apache 
- PHP 

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
Similar to logo.png, simply place a 16px X 16px ```favicon.ico``` file at the root of your PhotogSite install.

### Captions
PhotogSite will automagically detect the presence of captions contained within the metadata of each photo and display the caption if it finds one. To add captions to your images, open them in your favourite image editor and edit the image's "Description" metadata. Boom! Instant caption!

### Intro Text
If you'd like to display some introductory text at the beginning of a section, place a file named ```intro.html``` alongside your images inside your section's folder. The introductory text will display at the start of the portfolio section. Note that you must use HTML in order to write this file. You can find an example in ```_demo.sections/03_bears/intro.html```. Simply copy this file into your own section and edit it with your text editor.

### Adding Links and Content to the Sidebar
You can add content such as links and short paragraphs into the main navigation bar. Simply copy and rename ```demo.additional_links.html``` to ```additional_links.html``` and place it in PhotogSite's root directory. Open it in your text editor and follow the instructions inside. Some basic knowledge of HTML is required to edit this file.

### Videos
Videos are not yet supported but will be in a future release. 

## PhotogSite was Inspired by:
- [Stacey](http://www.staceyapp.com/)
- [Jonathan Waiter](http://www.jonathanwaiter.com/)
- [Cass Bird](http://www.cassbird.com/)
- [Indexhibit](http://www.indexhibit.org/)
- And my own personal need to have a super simple portfolio website that I can update easily! Life's too short to spend it updating your website - go shoot some pictures instead!

## Support

Please file a ticket here if you encounter issues. Thanks.

![It's free software](https://camo.githubusercontent.com/df781f87da2f2db87b5cc3125d5459bc70812112/687474703a2f2f64726f70732e6b796c65666f782e63612f31637147502b)