<?php if ($config['use_google_analytics']): ?>
  <script>
    (function(b,o,i,l,e,r){b.GoogleAnalyticsObject=l;b[l]||(b[l]=
    function(){(b[l].q=b[l].q||[]).push(arguments)});b[l].l=+new Date;
    e=o.createElement(i);r=o.getElementsByTagName(i)[0];
    e.src='//www.google-analytics.com/analytics.js';
    r.parentNode.insertBefore(e,r)}(window,document,'script','ga'));
    ga('create','<?php print $config['google_ua_code']; ?>');ga('send','pageview');
  </script>
<?php endif; ?>

<!-- 

  This site is built with PhotogSite, the PHP script that makes creating your
  photography portfolio online easy!

  See: https://github.com/jonathanbell/photogsite for more details! : ) 
  
-->