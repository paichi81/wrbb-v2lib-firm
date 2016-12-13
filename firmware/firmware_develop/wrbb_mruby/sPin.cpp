/*
 * Pin
 *
 * Copyright (c) 2016 paichi81
 */
#include <Arduino.h>
//#include <RTC.h>

#include <mruby.h>
#include <mruby/array.h>
#include <mruby/numeric.h>
#include <mruby/string.h>
#include <mruby/class.h>

#include "../wrbb.h"
#include "sKernel.h"


#define INPUT_PULLUP 2
#define INPUT 1
#define OUTPUT 0
#define HIGH 1
#define LOW 0


/*
  Pin.new(:pin_1)
*/

struct RClass *pin_class;
pin_class = mrb_define_class_under(mrb, mrb->kernel_module, "Pin", mrb->object_class);

RB_API mrb_value
mrb_assoc_new(mrb_state *mrb, mrb_value car)
{
}



// new(pin, mode)
  // mode=
  // mode
// on
// off
// state
// read
// write
// on?














void pin_Init(mrb_state *mrb)
{
  // 定数設定
  mrb_define_const(mrb, mrb->kernel_module, "INPUT_PULLUP",  mrb_fixnum_value(INPUT_PULLUP));
  mrb_define_const(mrb, mrb->kernel_module, "OUTPUT",  mrb_fixnum_value(OUTPUT));
  mrb_define_const(mrb, mrb->kernel_module, "INPUT", mrb_fixnum_value(INPUT));
  mrb_define_const(mrb, mrb->kernel_module, "OFF", mrb_fixnum_value(LOW));
  mrb_define_const(mrb, mrb->kernel_module, "LOW", mrb_fixnum_value(LOW));
  mrb_define_const(mrb, mrb->kernel_module, "ON", mrb_fixnum_value(HIGH));
  mrb_define_const(mrb, mrb->kernel_module, "HIGH", mrb_fixnum_value(HIGH));

  //Method定義

}
