$(document).ready(function() {

  $('#scroll-me').mousewheel(function(event, delta) {

    // delta * speed || A value of 73 seems reasonable however, different mice
    // and trackpads vary greatly in terms of sensitivity. This is probably
    // also affected by a setting that the user controls in the OS. 
    // See: https://github.com/jquery/jquery-mousewheel#the-deltas 
    this.scrollLeft -= (delta * 73);

    // preventDefault() will prevent the page from scrolling vertically. 
    // I don't know why you'd want to do this. Perhaps to cancel the vertical
    // scroll event from firing (and thus not firing two scroll events: one
    // for vertical and one for horizontal?). Allowing both events to fire 
    // seems to be a good idea because on a small screen, the page will still
    // scroll vertically. 
    
    //event.preventDefault();
    
  });

});



