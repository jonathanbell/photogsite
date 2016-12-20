<?php

// New line in the source HTML.
echo PHP_EOL.PHP_EOL;

// We are on the homepage.
if (!$section) {
  if ($config['show_random_homepage_image']) {
    print '<div class="splash-image"><img alt="A photograph taken by '.$config['site_title'].'." src="'.getRandomImage($portfolio_sections_with_ordinal, $sections_path).'" /></div>';
  }
} else { // We are not on the homepage.
  print '<article>'.PHP_EOL.'<h2 class="section-heading visuallyhidden">'.ucwords(dashesToSpaces($section)).'</h2>';
  print '<ul id="scroll-me" class="main-content-list">';
  $s = new Section($true_section_path, $section, $config);
  echo $s->display(); // Display all of the content : )
  print '</ul><!-- /.main-content-list -->'.PHP_EOL.'</article>';
} 