<?php

class Media {

  public function getPhotoCaption($filepath) {

    // TODO: Check if $filepath is a path to a valid image.

    $exif = @exif_read_data($filepath, 0, true, false);

    if (empty($exif['IFD0']['ImageDescription'])) {
      return false;
    } else {
      return $exif['IFD0']['ImageDescription'];
    }

  }

}