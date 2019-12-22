<?php

// New line in the source HTML.
echo PHP_EOL.PHP_EOL;

// We are on the homepage.
if (!$section) {
  if (file_exists(__DIR__.'/../splash.html')) {
    print '<div class="splash-html">';
      echo (file_get_contents(__DIR__.'/../splash.html'));
    print '</div>';
  }
  elseif ($config['show_random_homepage_image']) {
    print '<div class="splash-image"><img alt="A photograph taken by '.$config['site_title'].'." src="'.getRandomImage($portfolio_sections_with_ordinal, $sections_path).'" /></div>';
  }
} else { // We are not on the homepage.
  print '<article>'.PHP_EOL.'<h2 class="section-heading visuallyhidden">'.ucwords(dashesToSpaces($section)).'</h2>';
  $s = new Section($true_section_path, $section, $config);
  echo $s->display();
  print PHP_EOL.'</article>';
}
