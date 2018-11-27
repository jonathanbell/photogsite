<?php

class Media {

  public function getPhotoCaption($filepath) {

    // Check if $filepath is a path to a valid image.
    if (!file_exists($filepath)) return false;

    $exif = @exif_read_data($filepath, 0, true, false);

    if (empty($exif['IFD0']['ImageDescription'])) {
      return false;
    } else {
      return $exif['IFD0']['ImageDescription'];
    }

  }

}
