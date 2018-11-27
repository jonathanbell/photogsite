<?php

class Section extends Media {

  private $true_section_path;
  private $name;

  function __construct($true_section_path, $section, $config) {
    $this->name = $section;
    $this->true_section_path = $true_section_path;
    $this->config = $config;
  }

  private function getIntroText() {
    if (file_exists($this->true_section_path.'/intro.html')) {
      return file_get_contents($this->true_section_path.'/intro.html');
    } else {
      return false;
    }
  }

  private function getPhotos() {
    return glob($this->true_section_path.'/*.{tif,gif,png,jpg}', GLOB_BRACE);
  }

  // TODO: Support YouTube/Vimeo
  private function getVideos() {

  }

  private function displayPhotos() {
    $output = '';
    $output .= $this->getIntroText() ? '<li class="intro-text">'.$this->getIntroText().'</li>' : '';
    $photo_paths = $this->getPhotos();
    foreach ($photo_paths as $photo_path) {
      $output .= '<li class="image-item';
      $output .= $this->getPhotoCaption($photo_path) ? ' has-caption' : '';
      $output .= '">';
      $output .= '<img alt="';
      $output .= $this->getPhotoCaption($photo_path) ? $this->getPhotoCaption($photo_path) : 'A photograph taken by '.$this->config['site_title'];
      $output .= '" class="portfolio-image" src="'.webSafeSpaces(ltrim($photo_path, './')).'">';
      $output .= $this->getPhotoCaption($photo_path) ? '<p class="caption">'.$this->getPhotoCaption($photo_path).'</p>' : '';
      $output .= '</li>';
    }
    return $output;
  }

  // TODO: display YouTube/Vimeo videos
  private function displayVideos() {

  }

  public function display() {

    if (strtolower($this->name) != 'videos') {
      return $this->displayPhotos();
    } else {
      return $this->displayVideos();
    }

  }

}
