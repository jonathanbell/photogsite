<?php
declare(strict_types=1);

use PHPUnit\Framework\TestCase;

// https://stackoverflow.com/a/42117043/1171790
spl_autoload_register(function ($class_name) {
  $CLASSES_DIR = __DIR__.DIRECTORY_SEPARATOR.'classes'.DIRECTORY_SEPARATOR;
  $file = $CLASSES_DIR.'class.'.$class_name.'.inc';
  if(file_exists($file )) require_once($file);
});

include_once './inc/functions.inc';

final class Tests extends TestCase {

  public function testImageCaption(): void {
    $this->assertEquals(
      'Jacob, Summer 2010',
      (new Media)->getPhotoCaption(__DIR__.DIRECTORY_SEPARATOR.'_demo.sections'.DIRECTORY_SEPARATOR.'03_bears/test-bear.jpg')
    );
    $this->assertFalse(
      (new Media)->getPhotoCaption(__DIR__.DIRECTORY_SEPARATOR.'_demo.sections'.DIRECTORY_SEPARATOR.'03_bears/D.jpg')
    );
  }

  public function testDisplay(): void {
    $true_section_path = './_demo.sections/03_bears';
    $section = 'bears';
    $config = Array (
      'demo_mode' => true,
      'site_title' => 'Photogsite',
      'show_site_title' => 1,
      'email_address' => 'fake@fake.com',
      'show_contact_link' => 1,
      'blog_url' => 'http://credittocreation.jonathanbell.ca',
      'blog_title' => 'Tumblr',
      'show_blog_link' => 1,
      'promote_photogsite' => false,
      'show_copywrite' => false,
      'show_random_homepage_image' => 1,
      'use_google_analytics' => 0,
      'google_ua_code' => 'UA-26198999-1'
    );

    $section = new Section($true_section_path, $section, $config);
    $this->assertInternalType('string', $section->display());
  }
}
