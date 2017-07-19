<?php

namespace Drupal\compro_custom\Plugin\Field\FieldFormatter;

/**
 * @file
 * Contains
 *   \Drupal\compro_custom\Plugin\Field\FieldFormatter\ComproCustomFileLink.
 */

use Drupal\Core\Field\FieldItemListInterface;
use Drupal\Core\Field\FormatterBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Link;
use Drupal\Core\Url;

/**
 * Plugin implementation of the 'compro_custom_file_link' formatter.
 *
 * @FieldFormatter(
 *   id = "compro_custom_file_link",
 *   label = @Translation("Link"),
 *   field_types = {
 *     "file"
 *   }
 * )
 */
class ComproCustomFileLink extends FormatterBase {

  /**
   * {@inheritdoc}
   */
  public static function defaultSettings() {
    return array(
      'compro_custom_link_title' => '',
      'compro_custom_link_class' => '',
    ) + parent::defaultSettings();
  }

  /**
   * {@inheritdoc}
   */
  public function settingsForm(array $form, FormStateInterface $form_state) {
    $form = parent::settingsForm($form, $form_state);

    $form['compro_custom_link_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Link title'),
      '#description' => t('Enter an optional link title to be shown instead of file name'),
      '#default_value' => $this->getSetting('compro_custom_link_title'),
    );

    $form['compro_custom_link_class'] = array(
      '#type' => 'textfield',
      '#title' => t('Class'),
      '#description' => t('Enter an optional class to be applied to the link'),
      '#default_value' => $this->getSetting('compro_custom_link_class'),
    );

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function settingsSummary() {
    $summary = array();
    $summary[] = t('Displays a title link');
    return $summary;
  }

  /**
   * {@inheritdoc}
   */
  public function viewElements(FieldItemListInterface $items, $langcode) {
    $elements = array();

    // Loop through items.
    foreach ($items as $delta => $file) {
      $file = $file->entity;
      $url = Url::fromUri(
        $file->url(),
        array(
          'attributes' => array(
            'class' => array(
              $this->getSetting('compro_custom_link_class') !== NULL ? $this->getSetting('compro_custom_link_class') : '',
            ),
          ),
        )
      );
      $file_link = Link::fromTextAndUrl(
        ('compro_custom_link_title') !== NULL ?
          $this->getSetting('compro_custom_link_title') : $file->getFileName(), $url
      );
      $elements[$delta] = $file_link->toRenderable();
    }

    return $elements;
  }

}
