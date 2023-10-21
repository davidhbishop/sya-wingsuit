<?php

/**
 * @file
 * Functions to support theming blocks in the Wing suit theme.
 */

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 *
 * Theme block suggestion.
 * @param array $suggestions an array of theme suggestions
 * @param array $variables the set of variables
 */
function wingsuit_theme_suggestions_block_alter(array &$suggestions, array $variables): void {
  // Provide suggestion for block templates by custom block type.
  if (!empty($variables['elements']['content']['#block_content'])) {
    $block = $variables['elements']['content']['#block_content'];
    // Add `block--BLOCK-TYPE.html.twig`.
    $suggestions[] = 'block__' . $block->bundle();
    $view_mode = $variables['elements']['#configuration']['view_mode'];
    if (!empty($view_mode)) {
      // Add `block--BLOCK-TYPE--VIEW-MODE.html.twig`.
      $suggestions[] = 'block__' . $block->bundle() . '__' . $view_mode;
    }
  }
}
