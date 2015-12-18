<?php

/**
 * @file
 * Contains \Drupal\compro_custom\Plugin\Field\ComproSubmittedField.
 */

namespace Drupal\compro_custom\Plugin\Field\ComproSubmittedField;

use Drupal\Core\Field\FieldItemBase;
use Drupal\Core\Field\FieldStorageDefinitionInterface;
use Drupal\Core\TypedData\DataDefinition;

/**
 * Plugin implementation of the 'compro_submitted' field type.
 *
 * @FieldType(
 *   id = "compro_submitted",
 *   label = @Translation("Submitted"),
 *   description = @Translation("Author attribution for the content."),
 *   default_widget = "text",
 *   default_formatter = "string"
 * )
 */
class ComproSubmittedField extends FieldItemBase {

  /**
   * {@inheritdoc}
   */
  public static function schema(FieldStorageDefinitionInterface $field_definition) {
    return array(
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => 256,
          'not null' => FALSE,
        ),
      ),
    );
  }

  /**
   * {@inheritdoc}
   */
  public static function propertyDefinitions(FieldStorageDefinitionInterface $field_definition) {
    $property_definitions['value'] = DataDefinition::create('string')
      ->setLabel(t('Telephone number'));
    return $property_definitions;
  }

}
