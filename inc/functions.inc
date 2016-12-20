<?php

/**
 * Converts spaces and underscores to hyphens for use in URLs.
 * @param  string $string [description]
 * @return string         Returns URL safe portfolio section or file name.
 */
function spacesToDashes($string) {
  $string = preg_replace("/[\s_]/", "-", $string);
  return $string;
}

/**
 * Converts hypens to spaces for printing nicely formated, human readable strings.
 * @param  string $string [description]
 * @return string         The human readable format of the string (without hyphens).
 */
function dashesToSpaces($string) {
  $string = str_replace('-', ' ', $string);
  return $string;
}

/**
 * Converts spaces to websafe '%20' strings.
 * @param  string $string The string containing spaces.
 * @return string         The string with spaces converted to '%20'.
 */
function webSafeSpaces($string) {
  return str_replace(' ', '%20', ltrim($string, './'));
}

/**
 * Removes user added convents that keep portfolio sections and files in the desired order. 
 * @param  string $str The string to be trimmed.
 * @return string      The trimmed string.
 */
function removeOrdinalDelimiters($str) {
  $e = explode('_', $str);
  return end($e);
}

/**
 * Gets a random image to be displayed on the homepage.
 * @param  array $portfolio_sections_with_ordinal  All portfolio sections including thier ordinal, such as '01_section'.
 * @param  string $sections_path                   The path to the sections (usually '_sections')
 * @return string                                  A converted filepath pointing to a random image inside the sections. 
 */
function getRandomImage($portfolio_sections_with_ordinal, $sections_path) {
  shuffle($portfolio_sections_with_ordinal);
  $chosen_images = glob('.'.$sections_path.'/'.$portfolio_sections_with_ordinal[0].'/*.{tif,gif,png,jpg}', GLOB_BRACE);
  shuffle($chosen_images);
  return ltrim($chosen_images[0], './');
}