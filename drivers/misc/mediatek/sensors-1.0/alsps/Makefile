# In case the platform does NOT support this type of sensors
ccflags-y += -I$(srctree)/drivers/misc/mediatek/sensors-1.0/hwmon/include
obj-y   +=  alsps.o
obj-y   +=  alsps_factory.o
obj-y   +=  aal_control.o

obj-$(CONFIG_MTK_ALSPSHUB)      +=  alspshub/
obj-$(CONFIG_MTK_CM36558)	+=  cm36558/
obj-$(CONFIG_MTK_CM36652)	+=  cm36652/
obj-$(CONFIG_MTK_CM36686)	+=  cm36686/
obj-$(CONFIG_MTK_EPL2182)	+=  epl2182/
obj-$(CONFIG_MTK_APDS9930)	+=  APDS9930/
obj-$(CONFIG_MTK_LTR559)	+=  ltr559/
obj-$(CONFIG_MTK_STK3X1X_OT)	+=  stk3x1x_ot/
obj-$(CONFIG_MTK_STK3X1X)	+=  stk3x1x/
obj-$(CONFIG_MTK_LTR553)	+=  ltr553/
obj-$(CONFIG_MTK_EPL2570)	+=  epl2570/

