<div class="masthead">

  <h1 class="site-title"><?php if($config['demo_mode']) print 'Demo Mode: '; ?><a href="/"><?php print $config['site_title'] ?></a></h1>

  <?php if(file_exists('./logo.png')) print '<img class="site-logo" src="logo.png" alt="'.$config['site_title'].'&#39;s logo" />
'; ?>

  <nav class="main-nav">
    <?php
      foreach($portfolio_sections as $portfolio_section) {
        print '<div><a href="'.strtolower(spacesToDashes($portfolio_section)).'">'.dashesToSpaces($portfolio_section).'</a></div>'.PHP_EOL;
      }
    ?>
    <hr />
    <?php if (file_exists('./additional_links.html')) echo '<div class="additional-links">'.file_get_contents('./additional_links.html').'</div>'; ?>
    <?php if($config['show_blog_link']) print '<div><a href="'.$config['blog_url'].'">'.$config['blog_title'].'</a></div>' ?>
    <?php if($config['show_contact_link']) print '<div><a href="mailto:'.$config['email_address'].'">'.$config['email_address'].'</a></div>' ?>
  </nav>

  <?php if($config['demo_mode'] || $config['show_copywrite'] || $config['promote_photogsite']): ?>
    <footer class="site-info">
      <?php if($config['demo_mode']) print '<strong>Running in demo mode! Read <a style="background: rgba(111,111,211,0.7); padding: 1px;" target="_blank" href="https://github.com/jonathanbell/photogsite/blob/master/README.md">the documentation</a> for more information.</strong><br><br>'; ?>
      <?php if($config['show_copywrite']) print '&copy; '.date('Y').' '.$config['site_title']; ?>
      <?php if($config['promote_photogsite']) print '<small class="footer-item photogsite">Built with <a target="_blank" href="https://github.com/jonathanbell/photogsite">PhotogSite</a></small>' ?>
    </footer>
  <?php endif; ?>

</div><!-- /.masthead -->
