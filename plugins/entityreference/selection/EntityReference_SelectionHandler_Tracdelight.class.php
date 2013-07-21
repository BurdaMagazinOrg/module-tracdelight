<?php

class EntityReference_SelectionHandler_Tracdelight extends EntityReference_SelectionHandler_Generic {

  /**
   * Implements EntityReferenceHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {

    return new EntityReference_SelectionHandler_Tracdelight($field, $instance, $entity_type, $entity);
  }

  /**
   * Implements EntityReferenceHandler::settingsForm().
   */
  public static function settingsForm($field, $instance) {
    return array();
  }

  /**
   * Build an EntityFieldQuery to get referencable entities.
   */
  protected function buildEntityFieldQuery($match = NULL, $match_operator = 'CONTAINS') {

    $query = parent::buildEntityFieldQuery($match, $match_operator);

    if (isset($match)) {

      if ($query_string = arg(11)) {
        parse_str($query_string, $query_params);
        if (isset($query_params['ein'])) {
          $query->propertyCondition('ein', $query_params['ein'], $match_operator);
        }
      }
      else {
        $query->propertyCondition('title', $match, $match_operator);
      }
    }

    return $query;
  }

  /**
   * Implements EntityReferenceHandler::getReferencableEntities().
   */
  public function getReferencableEntities($match = NULL, $match_operator = 'CONTAINS', $limit = 0) {

    $entities = parent::getReferencableEntities($match, $match_operator, $limit);

    if (empty($entities)) {
      $entities['tracdelight_product'] = array();

      $products = array();
      if ($query_string = arg(11)) {
        parse_str($query_string, $query_params);
        if (isset($query_params['ein'])) {

          $query = array('EIN' => $query_params['ein']);
          $products = tracdelight_import_products($query);

        }
      } elseif (isset($match)) {

        $products = tracdelight_import_products(array('Query' => $match), 10);

      }

      foreach ($products as $product) {

        $entities['tracdelight_product'][$product['ein']] = $product['title'];

      }

    }

    return $entities;
  }

}
