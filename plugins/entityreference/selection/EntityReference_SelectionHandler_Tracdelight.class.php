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

      if ($ein = $this->_getEinFromUri()) {
        $query->propertyCondition('ein', $ein, $match_operator);
      } else if (tracedelight_string_seems_to_be_ein($match)) {
        $query->propertyCondition('ein', $match, $match_operator);
      } else {
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
      if ($ein = $this->_getEinFromUri()) {
        $query = array('EIN' => $ein);
        $products = tracdelight_import_products($query);
      }
      elseif (isset($match)) {
        $products = tracdelight_import_products(array('Query' => $match), 10);
      }

      foreach ($products as $product) {
        $entity_id = tracdelight_get_entity_id($product['ein']);
        if ($entity_id) {
          $entities['tracdelight_product'][$entity_id] = $product['title'];
        }
      }

    }

    return $entities;
  }

  protected function _getEinFromUri()
  {
    // td.oo link
    // weird drupal stuff.
    // 1              /2           /3     /5                      /6   /7               /8    /9      //10,11
    // entityreference/autocomplete/single/field_edelight_products/node/edelight_gallery/75261/http%3A//td.oo34.net/cl/aaid%3DVlpQAYKIMyDSTtHO%26ein%3D21x9s0irmygjktn3%26paid%3DlYVRbN7BUaBWfHq
    // entityreference/autocomplete/single/field_edelight_products/node/edelight_gallery/75261/http%3A//editorialshopping.tracdelight.com/Bunte/muuto-elevated-vase-grau%2Cqncf1el0uy9mhaop%2Ci
    if ($query_string = arg(11)) {
      parse_str($query_string, $query_params);

      if (is_array($query_params) && isset($query_params['ein'])) {
        return $query_params['ein'];
      } else if (preg_match('/\,(?P<ein>[a-z0-9]{16})\,/i', $query_string, $matches)) {
        return $matches['ein'];
      }
    }
    return false;
  }
}
