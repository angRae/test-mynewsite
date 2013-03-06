<?php
/**
 * @file
 * online_books_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function online_books_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function online_books_feature_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function online_books_feature_node_info() {
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
