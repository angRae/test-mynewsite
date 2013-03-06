<?php
/**
 * @file
 * book_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function book_content_type_node_info() {
  $items = array(
    'book_management' => array(
      'name' => t('Book management'),
      'base' => 'node_content',
      'description' => t('Book management'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
