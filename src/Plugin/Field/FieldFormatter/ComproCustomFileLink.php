<?php
namespace Drupal\compro_custom\Plugin\Field\FieldFormatter;

use Drupal\Core\Field\FieldItemListInterface;
use Drupal\Core\Field\FormatterBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Plugin implementation of the 'compro_custom_file_link' formatter
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
    );
  }

  /**
   * {@inheritdoc}
   */
  public function settingsForm(array $form, FormStateInterface $form_state) {
    $elements = array();

    $elements['compro_custom_link_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Link title'),
      '#description' => t('Enter an optional link title to be shown instead of file name'),
      '#default_value' => $this->getSetting('compro_custom_link_title'),
    );

    $elements['compro_custom_link_class'] = array(
      '#type' => 'textfield',
      '#title' => t('Class'),
      '#description' => t('Enter an optional class to be applied to the link'),
      '#default_value' => $this->getSetting('compro_custom_link_class'),
    );

    return $elements;
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

    // Loop through items
    foreach ($items as $delta => $item) {
      if ($this->getPluginId() == 'compro_custom_file_link') {
        $elements[$delta] = array(
          '#theme' => 'link',
          '#text' => $this->getSetting('compro_custom_link_title') ? $this->getSetting('compro_custom_link_title') : $item['filename'],
          '#path' => file_create_url($item['uri']),
          '#options' => array(
            'attributes' => array('class' => array($this->getSetting('compro_custom_link_class') ? $this->getSetting('compro_custom_link_class') : '')),
            'html' => FALSE,
          ),
        );
      }
    }

    return $elements;
  }
}