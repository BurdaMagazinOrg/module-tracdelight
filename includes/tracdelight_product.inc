<?php

class TracdelightProduct extends Entity {

  public function defaultLabel()
  {
    return isset($this->ein) ? $this->ein : NULL;
  }
}
