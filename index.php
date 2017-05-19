<?php

// Exceptions for local testing.
if ($_SERVER['HTTP_HOST'] == 'localhost' || $_SERVER['HTTP_HOST'] == 'dev.jonathanbell.ca') {
  date_default_timezone_set('America/Los_Angeles');
  error_reporting(E_ALL);
  ini_set('display_errors', 1);
} else {
  error_reporting(0); // Production.
}

// The user has moved or renamed the all important 'config.ini' file.
if (!file_exists(__DIR__.'/config.ini') && !file_exists(__DIR__.'/demo.config.ini')) {
  exit("Failed to locate a configuration file! Ensure that \"config.ini\" is in the same folder as the \"index.php\" file. Perhaps you have moved or renamed the file? Terminating PhotogSite...");
}

if (!file_exists(__DIR__.'/config.ini')) {
  $config = parse_ini_file(__DIR__.'/demo.config.ini');
} else {
  $config = parse_ini_file(__DIR__.'/config.ini');
}

// $section is the app's main 'route'.
// We tidy this in .htaccess for clean URLs. : )
$section = FALSE;
if (isset($_GET['section'])) {
  // Replace any occurences of a slash in $_GET['section'] before setting $section..
  // This could occur on Nginx but probably not on Apache.
  $section = str_replace('/', '', $_GET['section']);
}

/**
 * Define autoloader.
 * @param string $class_name
 */
function __autoload($class_name) {
  require_once('./classes/class.'.$class_name.'.inc');
}

// Include all helper functions.
require_once('./inc/functions.inc');

$sections_path = $config['demo_mode'] ? '/_demo.sections' : '/_sections';

// Get all of our portfolio sections.
$portfolio_sections_with_ordinal = [];
$portfolio_sections = [];
foreach (glob(__DIR__.'/'.$sections_path.'/*', GLOB_ONLYDIR) as $section_path) {
  $base_section_path = basename($section_path);
  $portfolio_sections_with_ordinal[] = $base_section_path;
  $portfolio_sections[] = removeOrdinalDelimiters($base_section_path);
}

// Check if we have an invalid section.
if ($section && !in_array(dashesToSpaces($section), $portfolio_sections)) {
  // If we have an invalid section requested, send a 404 and exit.
  header('HTTP/1.0 404 Not Found');
  echo (file_get_contents('404.html'));
  exit();
}

// We will pass this path to our Section class.
$section_id = array_search(dashesToSpaces($section), $portfolio_sections);
$true_section_path = '.'.$sections_path.'/'.$portfolio_sections_with_ordinal[$section_id];

// We all good cuz. Let's get this party started!
require_once(__DIR__.'/inc/template.inc');

?>
