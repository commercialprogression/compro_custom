<?php

/**
 * @file
 * Administration callbacks for the module.
 */

/**
 * Menu callback function for compro_custom administration.
 */
function compro_custom_admin($form, &$form_state) {
  // Load module vars
  $compro_custom = variable_get('compro_custom', '');

  // Make form a tree.
  $form['#tree'] = TRUE;

  $form['compro_custom']['icon_enable'] = array(
    '#default_value' => isset($compro_custom['icon_enable']) ? $compro_custom['icon_enable'] : 1,
    '#title' => t('Include icon font and CSS on all pages.'),
    '#type' => 'checkbox',
  );

  // Demo icons and CSS.
  $form['#attached']['css'] = array(
    drupal_get_path('module', 'compro_custom') . '/icons/compro_custom.css',
  );
  $form['icon_demo'] = array(
    '#type' => 'container',
  );
  $form['icon_demo']['icons'] = array(
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#type' => 'fieldset',
    '#title' => t('Available icons'),
  );
  $form['icon_demo']['icons']['table'] = array(
    '#markup' => _compro_custom_icon_table(),
  );
  $form['icon_demo']['social'] = array(
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#type' => 'fieldset',
    '#title' => t('Available social links'),
  );
  $form['icon_demo']['social']['table'] = array(
    '#markup' => _compro_custom_social_table(),
  );
  
  return system_settings_form($form);
}

/**
 * Helper to return all the icon classes.
 */
function _compro_custom_icon_classes() {
  return array(
    'airplane' => array('unicode' => '\2708'),
    'amazon' => array('unicode' => '\1e01'),
    'android' => array('unicode' => '\1f4e0'),
    'apple' => array('unicode' => '\1f34e'),
    'arrow-down' => array('unicode' => '\2193'),
    'arrow-left' => array('unicode' => '\2190'),
    'arrow-right' => array('unicode' => '\2192'),
    'arrow-up' => array('unicode' => '\2191'),
    'basket' => array('unicode' => '\1f6cd'),
    'bell' => array('unicode' => '\1f514'),
    'bitbucket' => array('unicode' => '\1f5d1'),
    'bitcoin' => array('unicode' => '\e3f'),
    'book-cover' => array('unicode' => '\1f4d5'),
    'camera' => array('unicode' => '\1f4f7'),
    'cc-amex' => array('unicode' => '\24e7'),
    'cc-discover' => array('unicode' => '\24d3'),
    'cc-mastercard' => array('unicode' => '\24dc'),
    'cc-paypal' => array('unicode' => '\24df'),
    'cc-stripe' => array('unicode' => '\24e2'),
    'cc-visa' => array('unicode' => '\24e5'),
    'chat-balloon' => array('unicode' => '\1f4ac'),
    'checkmark' => array('unicode' => '\2713'),
    'delicious' => array('unicode' => '\1f67e'),
    'direction' => array('unicode' => '\21d7'),
    'dropbox' => array('unicode' => '\237d'),
    'drupal-drop' => array('unicode' => '\1f4a7'),
    'ebay' => array('unicode' => '\6fb3'),
    'envelope' => array('unicode' => '\2709'),
    'facebook' => array('unicode' => '\192'),
    'favorites' => array('unicode' => '\1f516'),
    'fax' => array('unicode' => '\260e'),
    'file-audio' => array('unicode' => '\3609'),
    'file-code' => array('unicode' => '\4e5a'),
    'file-excel' => array('unicode' => '\67f5'),
    'file-image' => array('unicode' => '\753b'),
    'file-pdf' => array('unicode' => '\6ce5'),
    'file-plain' => array('unicode' => '\1f5ce'),
    'file-powerpoint' => array('unicode' => '\8a00'),
    'file-video' => array('unicode' => '\3979'),
    'file-word' => array('unicode' => '\5b57'),
    'file-zip' => array('unicode' => '\64c1'),
    'flag' => array('unicode' => '\2691'),
    'flickr' => array('unicode' => '\2824'),
    'folder' => array('unicode' => '\1f4c1'),
    'gear' => array('unicode' => '\2699'),
    'ghostbusters' => array('unicode' => '\20e0'),
    'github' => array('unicode' => '\1f419'),
    'globe' => array('unicode' => '\1f30e'),
    'google' => array('unicode' => '\261'),
    'gwallet' => array('unicode' => '\24e6'),
    'hacker-news' => array('unicode' => '\232'),
    'hamburger' => array('unicode' => '\2261'),
    'heart' => array('unicode' => '\2764'),
    'house' => array('unicode' => '\2302'),
    'html5' => array('unicode' => '\2684'),
    'instagramm' => array('unicode' => '\1f4f8'),
    'itinerary' => array('unicode' => '\1f4c5'),
    'link-ext' => array('unicode' => '\1f517'),
    'linkedin' => array('unicode' => '\1f13b'),
    'location' => array('unicode' => '\2316'),
    'magnifying-glass-minus' => array('unicode' => '\2beb'),
    'magnifying-glass-plus' => array('unicode' => '\2bea'),
    'magnifying-glass' => array('unicode' => '\1f50d'),
    'meetup' => array('unicode' => '\2133'),
    'microphone' => array('unicode' => '\1f3a4'),
    'move-handle' => array('unicode' => '\1f542'),
    'padlock-open' => array('unicode' => '\1f513'),
    'padlock' => array('unicode' => '\1f512'),
    'paperclip' => array('unicode' => '\1f4ce'),
    'picture' => array('unicode' => '\1f533'),
    'pin' => array('unicode' => '\22a4'),
    'pinterest' => array('unicode' => '\2118'),
    'price-tag' => array('unicode' => '\3868'),
    'printer' => array('unicode' => '\1f5b6'),
    'recycle' => array('unicode' => '\2672'),
    'reddit' => array('unicode' => '\1f47d'),
    'rss-symbol' => array('unicode' => '\2a9c'),
    'share-symbol' => array('unicode' => '\5171'),
    'silhouette' => array('unicode' => '\1f464'),
    'skype' => array('unicode' => '\24c8'),
    'slideshare' => array('unicode' => '\2b13'),
    'spinner-double' => array('unicode' => '\21bb'),
    'stackoverflow' => array('unicode' => '\1d363'),
    'star' => array('unicode' => '\2605'),
    'stumbleupon' => array('unicode' => '\1515'),
    'telephone' => array('unicode' => '\1f4de'),
    'thumbs-up' => array('unicode' => '\1f44d'),
    'ticket' => array('unicode' => '\1f3ab'),
    'trash' => array('unicode' => '\5783'),
    'tree-leaf' => array('unicode' => '\1f342'),
    'tumblr' => array('unicode' => '\1d69d'),
    'twitter' => array('unicode' => '\1f426'),
    'video-play' => array('unicode' => '\1f39e'),
    'vimeo' => array('unicode' => '\24b1'),
    'vine' => array('unicode' => '\2c71'),
    'wheelchair' => array('unicode' => '\267f'),
    'wikipedia' => array('unicode' => '\174'),
    'yahoo' => array('unicode' => '\24e'),
    'yelp' => array('unicode' => '\2837'),
    'youtube' => array('unicode' => '\6898'),
  );
}

/**
 * Helper to theme a table showing icons, markup, and unicode.
 */
function _compro_custom_icon_table() {
  $variables = array(
    'header' => array(
      t('Class'),
      t('Icon'),
      t('Markup'),
      t('Unicode'),
    ),
    'rows' => array(),
    'sticky' => TRUE,
  );
  
  // Get each row.
  foreach (_compro_custom_icon_classes() as $class => $data) {
    $variables['rows'][] = array(
      check_plain($class),
      '<span class="icon ' . check_plain($class) . '"></span>',
      '<code>&lt;span class="icon ' . check_plain($class) . '"&gt;&lt;/span&gt;</code>',
      $data['unicode'],
    );
  }
  
  return theme('table', $variables);
}

/**
 * Helper to return socials.
 */
function _compro_custom_social_icons() {
  return array(
    'delicious' => array('unicode' => '\1f67e', 'hover' => '#31a9ff'),
    'facebook' => array('unicode' => '\192', 'hover' => '#3b5998'),
    'flickr' => array('unicode' => '\2824', 'hover' => '#ff0084'),
    'github' => array('unicode' => '\1f419', 'hover' => '#333'),
    'google' => array('unicode' => '\261', 'hover' => '#dd4b39'),
    'instagram' => array('unicode' => '\1f4f8', 'hover' => '#3f729b'),
    'linkedin' => array('unicode' => '\1f13b', 'hover' => '#007bb6'),
    'meetup' => array('unicode' => '\2133', 'hover' => '#e0393e'),
    'pinterest' => array('unicode' => '\2118', 'hover' => '#cb2027'),
    'reddit' => array('unicode' => '\1f47d', 'hover' => 'orangered'),
    'twitter' => array('unicode' => '\1f426', 'hover' => '#00aced'),
    'vimeo' => array('unicode' => '\24b1', 'hover' => '#aad450'),
    'youtube' => array('unicode' => '\6898', 'hover' => '#b00'),
  );
}

/**
 * Helper to make social demos.
 */
function _compro_custom_social_table() {
  $variables = array(
    'attributes' => array(
      'class' => array('social'),
    ),
    'header' => array(
      t('Service'),
      t('Example'),
      t('Markup (in .social container)'),
      t('Unicode'),
    ),
    'rows' => array(),
    'sticky' => TRUE,
  );
  
  // Special rows.
  $variables['rows'][] = array(
    'external link',
    '<a href="http://example.com">example</a>',
    '<code>&lt;a href="http://example.com"&gt;example&lt;/a&gt;</code>',
    '\1f517',
  );
  $variables['rows'][] = array(
    'rss',
    '<a href="/rss">rss</a>',
    '<code>&lt;a href="http://example.com/rss"&gt;rss&lt;/a&gt;</code>',
    '\2a9c',
  );
  $variables['rows'][] = array(
    'email',
    '<a href="mailto:brad@commercialprogression.com">Email me</a>',
    '<code>&lt;a href="mailto:name@example.com"&gt;email me&lt;/a&gt;</code>',
    '\2709',
  );
  
  // Get each row.
  foreach (_compro_custom_social_icons() as $fragment => $data) {
    $variables['rows'][] = array(
      $fragment,
      '<a href="http://www.' . $fragment . '.com">' . $fragment . '</a>',
      '<code>&lt;a href="http://www.' . $fragment . '.com"&gt;' . $fragment . '&lt;/a&gt;</code>',
      $data['unicode'],
    );
  }
  
  return theme('table', $variables);
}