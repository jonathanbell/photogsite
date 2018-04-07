<!DOCTYPE html>
<html class="no-js">

<head>
  <meta charset="utf-8">
  <title>
  <?php 
    print $config['site_title']; 
    if ($section) print ': '.ucwords(dashesToSpaces($section)); 
  ?>
  </title>
  <meta name="description" content="The online photography portfolio of <?php print $config['site_title'] ?>">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  
  <?php

    if (!file_exists('./favicon.ico')) {
      print '<!-- Place favicon.ico and (optionally) an apple-touch-icon.png in the same directory as index.php if you want a favicon on your site. -->';
    }
    
    $css = '';
    foreach (glob('./css/*.css') as $css_file) {
      $css .= file_get_contents($css_file);
    }

    // Remove comments.
    $css = preg_replace('!/\*[^*]*\*+([^/][^*]*\*+)*/!', '', $css);
    // Remove space after colons.
    $css = str_replace(': ', ':', $css);
    // Remove whitespace.
    $css = str_replace(array("\r\n", "\r", "\n", "\t", '  ', '    ', '    '), '', $css);

    file_put_contents('./style.css', $css);

  ?>

  <link rel="stylesheet" type="text/css" href="style.css">

</head>

<body class="<?php print $section ? 'not-front section-'.strtolower(spacesToDashes($section)) : 'front' ?>">

  <?php require_once __DIR__.'/menubar.inc'; ?>
  <?php require_once __DIR__.'/content.inc'; ?>
  <?php require_once __DIR__.'/footer.inc'; ?>

  <?php 

    $js = '';
    foreach (glob('./js/*.js') as $js_file) {
      if ($js_file != 'demo.user.css') {
        $js .= PHP_EOL.'/* ******************************** */'.PHP_EOL.file_get_contents($js_file).PHP_EOL.'/* ******************************** */'.PHP_EOL;
      }
    }

    file_put_contents('./bundle.js', $js);

  ?>

  <script src="bundle.js"></script>

</body>
</html>
