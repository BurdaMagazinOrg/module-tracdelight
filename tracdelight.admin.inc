<?php

class TracdelightProductUIController extends EntityDefaultUIController {

}

/**
 * Task Form.
 */
/*
 *

CREATE TABLE `tracdelight_product` (
  `ein` varchar(16) NOT NULL COMMENT 'Product EIN',
  `detail_page_url` varchar(512) DEFAULT '' COMMENT 'Detail Page Url.',
  `title` varchar(256) DEFAULT '' COMMENT 'Title of a product.',
  `manufacturer` varchar(256) DEFAULT '' COMMENT 'Manufacturer of a product.',
  `brand` varchar(256) DEFAULT '' COMMENT 'Brand of a product.',
  `description` text COMMENT 'Description of a product.',
  `amount` decimal(7,2) DEFAULT NULL COMMENT 'Amount of a product.',
  `price_old` decimal(7,2) DEFAULT NULL COMMENT 'Old price of a product.',
  `base_price` decimal(7,2) DEFAULT NULL COMMENT 'Base price of a product.',
  `currency_code` varchar(8) DEFAULT '' COMMENT 'Currency code of a product.',
  `formatted_price` varchar(64) DEFAULT '' COMMENT 'Formatted price of a product.',
  `formatted_price_old` varchar(64) DEFAULT '' COMMENT 'Old formatted price of a product.',
  `image_base` varchar(256) DEFAULT '' COMMENT 'Base image path of a product.',
  `active` int(11) DEFAULT '1' COMMENT 'Product is available in shop',
  PRIMARY KEY (`ein`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



 */