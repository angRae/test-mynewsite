<?php
/**
 * @file
 * online_books_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function online_books_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:taxonomy/term/1
  $menu_links['main-menu:taxonomy/term/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/1',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Fiction',
    'options' => array(
      'attributes' => array(
        'title' => 'Fiction',
      ),
    ),
    'module' => 'taxonomy_menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '0',
  );
  // Exported menu link: main-menu:taxonomy/term/2
  $menu_links['main-menu:taxonomy/term/2'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/2',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Sci-Fi',
    'options' => array(
      'attributes' => array(
        'title' => 'Sci-Fi',
      ),
    ),
    'module' => 'taxonomy_menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '0',
  );
  // Exported menu link: main-menu:taxonomy/term/3
  $menu_links['main-menu:taxonomy/term/3'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/3',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Scientific publications',
    'options' => array(
      'attributes' => array(
        'title' => 'Scientific publications',
      ),
    ),
    'module' => 'taxonomy_menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '0',
  );
  // Exported menu link: main-menu:taxonomy/term/4
  $menu_links['main-menu:taxonomy/term/4'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/4',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Other',
    'options' => array(
      'attributes' => array(
        'title' => 'Other',
      ),
    ),
    'module' => 'taxonomy_menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '0',
  );
  // Exported menu link: navigation:isbn
  $menu_links['navigation:isbn'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'isbn',
    'router_path' => 'isbn',
    'link_title' => 'View books from ISBNdb.com',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Fiction');
  t('Other');
  t('Sci-Fi');
  t('Scientific publications');
  t('View books from ISBNdb.com');


  return $menu_links;
}
