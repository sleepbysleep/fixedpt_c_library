# fixedpt_c_library
Fixed-point arithmetic c library inspired by Atmel Software Framework, and en.wikipedia.org/wiki/Q_(number_format)

# Q format
Q is a fixed point number format where the number of fractional bits (and optionally the number of integer bits) is specified.
For example, a Q15 number has 15 fractional bits; a Q1.14 number has 1 integer bit and 14 fractional bits.
and in applications that require constant resolution.
 - from wikipedia.com

# 16bit format
Q14.1 - "SIIIIIIIIIIIIIIF" <- -16384 < float < 16384
Q13.2 - "SIIIIIIIIIIIIIFF" <-  -8192 < float < 8192
Q12.3 - "SIIIIIIIIIIIIFFF" <-  -4096 < float < 4096
Q11.4 - "SIIIIIIIIIIIFFFF" <-  -2048 < float < 2048
Q10.5 - "SIIIIIIIIIIFFFFF" <-  -1024 < float < 1024
Q9.6  - "SIIIIIIIIIFFFFFF" <-   -512 < float < 512
Q8.7  - "SIIIIIIIIFFFFFFF" <-   -256 < float < 256
Q7.8  - "SIIIIIIIFFFFFFFF" <-   -128 < float < 128
Q6.9  - "SIIIIIIFFFFFFFFF" <-    -64 < float < 64
Q5.10 - "SIIIIIFFFFFFFFFF" <-    -32 < float < 32
Q4.11 - "SIIIIFFFFFFFFFFF" <-    -16 < float < 16
Q3.12 - "SIIIFFFFFFFFFFFF" <-     -8 < float < 8
Q2.13 - "SIIFFFFFFFFFFFFF" <-     -4 < float < 4
Q1.14 - "SIFFFFFFFFFFFFFF" <-     -2 < float < 2
Q0.15 - "SFFFFFFFFFFFFFFF" <-     -1 < float < 1
where S is sign bit, I is integer bit, and F is fractional bit.

  In float-typed conatiner,
  Their unit resolution are;
	Q14.1:	5.000000000000000000e-01
	Q13.2:	2.500000000000000000e-01
	Q12.3:	1.250000000000000000e-01
	Q11.4:	6.250000000000000000e-02
	Q10.5:	3.125000000000000000e-02
	Q9.6:	1.562500000000000000e-02
	Q8.7:	7.812500000000000000e-03
	Q7.8:	3.906250000000000000e-03
	Q6.9:	1.953125000000000000e-03
	Q5.10:	9.765625000000000000e-04
	Q4.11:	4.882812500000000000e-04
	Q3.12:	2.441406250000000000e-04
	Q2.13:	1.220703125000000000e-04
	Q1.14:	6.103515625000000000e-05
	Q0.15:	3.051757812500000000e-05
  And the exact covering ranges are;
	Q14.1:	[-1.638400000000000000e+04, 1.638350000000000000e+04]
	Q13.2:	[-8.192000000000000000e+03, 8.191750000000000000e+03]
	Q12.3:	[-4.096000000000000000e+03, 4.095875000000000000e+03]
	Q11.4:	[-2.048000000000000000e+03, 2.047937500000000000e+03]
	Q10.5:	[-1.024000000000000000e+03, 1.023968750000000000e+03]
	Q9.6:	[-5.120000000000000000e+02, 5.119843750000000000e+02]
	Q8.7:	[-2.560000000000000000e+02, 2.559921875000000000e+02]
	Q7.8:	[-1.280000000000000000e+02, 1.279960937500000000e+02]
	Q6.9:	[-6.400000000000000000e+01, 6.399804687500000000e+01]
	Q5.10:	[-3.200000000000000000e+01, 3.199902343750000000e+01]
	Q4.11:	[-1.600000000000000000e+01, 1.599951171875000000e+01]
	Q3.12:	[-8.000000000000000000e+00, 7.999755859375000000e+00]
	Q2.13:	[-4.000000000000000000e+00, 3.999877929687500000e+00]
	Q1.14:	[-2.000000000000000000e+00, 1.999938964843750000e+00]
	Q0.15:	[-1.000000000000000000e+00, 9.999694824218750000e-01]

  In double-typed conatiner,
  Their unit resolution are;
	Q14.1:	5.000000000000000000e-01
	Q13.2:	2.500000000000000000e-01
	Q12.3:	1.250000000000000000e-01
	Q11.4:	6.250000000000000000e-02
	Q10.5:	3.125000000000000000e-02
	Q9.6:	1.562500000000000000e-02
	Q8.7:	7.812500000000000000e-03
	Q7.8:	3.906250000000000000e-03
	Q6.9:	1.953125000000000000e-03
	Q5.10:	9.765625000000000000e-04
	Q4.11:	4.882812500000000000e-04
	Q3.12:	2.441406250000000000e-04
	Q2.13:	1.220703125000000000e-04
	Q1.14:	6.103515625000000000e-05
	Q0.15:	3.051757812500000000e-05
  And the exact covering ranges are;
	Q14.1:	[-1.638400000000000000e+04, 1.638350000000000000e+04]
	Q13.2:	[-8.192000000000000000e+03, 8.191750000000000000e+03]
	Q12.3:	[-4.096000000000000000e+03, 4.095875000000000000e+03]
	Q11.4:	[-2.048000000000000000e+03, 2.047937500000000000e+03]
	Q10.5:	[-1.024000000000000000e+03, 1.023968750000000000e+03]
	Q9.6:	[-5.120000000000000000e+02, 5.119843750000000000e+02]
	Q8.7:	[-2.560000000000000000e+02, 2.559921875000000000e+02]
	Q7.8:	[-1.280000000000000000e+02, 1.279960937500000000e+02]
	Q6.9:	[-6.400000000000000000e+01, 6.399804687500000000e+01]
	Q5.10:	[-3.200000000000000000e+01, 3.199902343750000000e+01]
	Q4.11:	[-1.600000000000000000e+01, 1.599951171875000000e+01]
	Q3.12:	[-8.000000000000000000e+00, 7.999755859375000000e+00]
	Q2.13:	[-4.000000000000000000e+00, 3.999877929687500000e+00]
	Q1.14:	[-2.000000000000000000e+00, 1.999938964843750000e+00]
	Q0.15:	[-1.000000000000000000e+00, 9.999694824218750000e-01]

# 32bit format
  Q30_1  - SIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIF <- -1073741824 < float < 1073741824
  Q29_2  - SIIIIIIIIIIIIIIIIIIIIIIIIIIIIIFF <- -536870912 < float < 536870912
  Q28_3  - SIIIIIIIIIIIIIIIIIIIIIIIIIIIIFFF <- -268435456 < float < 268435456
  Q27_4  - SIIIIIIIIIIIIIIIIIIIIIIIIIIIFFFF <- -134217728 < float < 134217728
  Q26_5  - SIIIIIIIIIIIIIIIIIIIIIIIIIIFFFFF <- -67108864 < float < 67108864
  Q25_6  - SIIIIIIIIIIIIIIIIIIIIIIIIIFFFFFF <- -33554432 < float < 33554432
  Q24_7  - SIIIIIIIIIIIIIIIIIIIIIIIIFFFFFFF <- -16777216 < float < 16777216
  Q23_8  - SIIIIIIIIIIIIIIIIIIIIIIIFFFFFFFF <- -8388608 < float < 8388608
  Q22_9  - SIIIIIIIIIIIIIIIIIIIIIIFFFFFFFFF <- -4194304 < float < 4194304
  Q21_10 - SIIIIIIIIIIIIIIIIIIIIIFFFFFFFFFF <- -2097152 < float < 2097152
  Q20_11 - SIIIIIIIIIIIIIIIIIIIIFFFFFFFFFFF <- -1048576 < float < 1048576
  Q19_12 - SIIIIIIIIIIIIIIIIIIIFFFFFFFFFFFF <- -524288 < float < 524288
  Q18_13 - SIIIIIIIIIIIIIIIIIIFFFFFFFFFFFFF <- -262144 < float < 262144
  Q17_14 - SIIIIIIIIIIIIIIIIIFFFFFFFFFFFFFF <- -131072 < float < 131072
  Q16_15 - SIIIIIIIIIIIIIIIIFFFFFFFFFFFFFFF <- -65536 < float < 65536
  Q15_16 - SIIIIIIIIIIIIIIIFFFFFFFFFFFFFFFF <- -32768 < float < 32768
  Q14_17 - SIIIIIIIIIIIIIIFFFFFFFFFFFFFFFFF <- -16384 < float < 16384
  Q13_18 - SIIIIIIIIIIIIIFFFFFFFFFFFFFFFFFF <- -8192 < float < 8192
  Q12_19 - SIIIIIIIIIIIIFFFFFFFFFFFFFFFFFFF <- -4096 < float < 4096
  Q11_20 - SIIIIIIIIIIIFFFFFFFFFFFFFFFFFFFF <- -2048 < float < 2048
  Q10_21 - SIIIIIIIIIIFFFFFFFFFFFFFFFFFFFFF <= -1024 < float < 1024
  Q9_22  - SIIIIIIIIIFFFFFFFFFFFFFFFFFFFFFF <= -512 < float < 512
  Q8_23  - SIIIIIIIIFFFFFFFFFFFFFFFFFFFFFFF <= -256 < float < 256
  Q7_24  - SIIIIIIIFFFFFFFFFFFFFFFFFFFFFFFF <= -128 < float < 128
  Q6_25  - SIIIIIIFFFFFFFFFFFFFFFFFFFFFFFFF <= -64 < float < 64
  Q5_26  - SIIIIIFFFFFFFFFFFFFFFFFFFFFFFFFF <=  -32 < float < 32
  Q4_27  - SIIIIFFFFFFFFFFFFFFFFFFFFFFFFFFF <= -16 < float < 16
  Q3_28  - SIIIFFFFFFFFFFFFFFFFFFFFFFFFFFFF <= -8 < float < 8
  Q2_29  - SIIFFFFFFFFFFFFFFFFFFFFFFFFFFFFF <= -4 < float < 4
  Q1_30  - SIFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF <= -2 < float < 2
  Q0_31  - SFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF <= -1 < float < 1
  , where S is sign bit, I is integer bit, and F is fractional bit.

  In float-typed conatiner,
  Their unit resolution are;
	Q30.1:	5.000000000000000000e-01
	Q29.2:	2.500000000000000000e-01
	Q28.3:	1.250000000000000000e-01
	Q27.4:	6.250000000000000000e-02
	Q26.5:	3.125000000000000000e-02
	Q25.6:	1.562500000000000000e-02
	Q24.7:	7.812500000000000000e-03
	Q23.8:	3.906250000000000000e-03
	Q22.9:	1.953125000000000000e-03
	Q21.10:	9.765625000000000000e-04
	Q20.11:	4.882812500000000000e-04
	Q19.12:	2.441406250000000000e-04
	Q18.13:	1.220703125000000000e-04
	Q17.14:	6.103515625000000000e-05
	Q16.15:	3.051757812500000000e-05
	Q15.16:	1.525878906250000000e-05
	Q14.17:	7.629394531250000000e-06
	Q13.18:	3.814697265625000000e-06
	Q12.19:	1.907348632812500000e-06
	Q11.20:	9.536743164062500000e-07
	Q10.21:	4.768371582031250000e-07
	Q9.22:	2.384185791015625000e-07
	Q8.23:	1.192092895507812500e-07
	Q7.24:	5.960464477539062500e-08
	Q6.25:	2.980232238769531250e-08
	Q5.26:	1.490116119384765625e-08
	Q4.27:	7.450580596923828125e-09
	Q3.28:	3.725290298461914062e-09
	Q2.29:	1.862645149230957031e-09
	Q1.30:	9.313225746154785156e-10
	Q0.31:	4.656612873077392578e-10
  And the exact covering ranges are;
	Q30.1:	[-1.073741824000000000e+09, 1.073741824000000000e+09]
	Q29.2:	[-5.368709120000000000e+08, 5.368709120000000000e+08]
	Q28.3:	[-2.684354560000000000e+08, 2.684354560000000000e+08]
	Q27.4:	[-1.342177280000000000e+08, 1.342177280000000000e+08]
	Q26.5:	[-6.710886400000000000e+07, 6.710886400000000000e+07]
	Q25.6:	[-3.355443200000000000e+07, 3.355443200000000000e+07]
	Q24.7:	[-1.677721600000000000e+07, 1.677721600000000000e+07]
	Q23.8:	[-8.388608000000000000e+06, 8.388608000000000000e+06]
	Q22.9:	[-4.194304000000000000e+06, 4.194304000000000000e+06]
	Q21.10:	[-2.097152000000000000e+06, 2.097152000000000000e+06]
	Q20.11:	[-1.048576000000000000e+06, 1.048576000000000000e+06]
	Q19.12:	[-5.242880000000000000e+05, 5.242880000000000000e+05]
	Q18.13:	[-2.621440000000000000e+05, 2.621440000000000000e+05]
	Q17.14:	[-1.310720000000000000e+05, 1.310720000000000000e+05]
	Q16.15:	[-6.553600000000000000e+04, 6.553600000000000000e+04]
	Q15.16:	[-3.276800000000000000e+04, 3.276800000000000000e+04]
	Q14.17:	[-1.638400000000000000e+04, 1.638400000000000000e+04]
	Q13.18:	[-8.192000000000000000e+03, 8.192000000000000000e+03]
	Q12.19:	[-4.096000000000000000e+03, 4.096000000000000000e+03]
	Q11.20:	[-2.048000000000000000e+03, 2.048000000000000000e+03]
	Q10.21:	[-1.024000000000000000e+03, 1.024000000000000000e+03]
	Q9.22:	[-5.120000000000000000e+02, 5.120000000000000000e+02]
	Q8.23:	[-2.560000000000000000e+02, 2.560000000000000000e+02]
	Q7.24:	[-1.280000000000000000e+02, 1.280000000000000000e+02]
	Q6.25:	[-6.400000000000000000e+01, 6.400000000000000000e+01]
	Q5.26:	[-3.200000000000000000e+01, 3.200000000000000000e+01]
	Q4.27:	[-1.600000000000000000e+01, 1.600000000000000000e+01]
	Q3.28:	[-8.000000000000000000e+00, 8.000000000000000000e+00]
	Q2.29:	[-4.000000000000000000e+00, 4.000000000000000000e+00]
	Q1.30:	[-2.000000000000000000e+00, 2.000000000000000000e+00]
	Q0.31:	[-1.000000000000000000e+00, 1.000000000000000000e+00]

  In double-typed conatiner,
  Their unit resolution are;
	Q30.1:	5.000000000000000000e-01
	Q29.2:	2.500000000000000000e-01
	Q28.3:	1.250000000000000000e-01
	Q27.4:	6.250000000000000000e-02
	Q26.5:	3.125000000000000000e-02
	Q25.6:	1.562500000000000000e-02
	Q24.7:	7.812500000000000000e-03
	Q23.8:	3.906250000000000000e-03
	Q22.9:	1.953125000000000000e-03
	Q21.10:	9.765625000000000000e-04
	Q20.11:	4.882812500000000000e-04
	Q19.12:	2.441406250000000000e-04
	Q18.13:	1.220703125000000000e-04
	Q17.14:	6.103515625000000000e-05
	Q16.15:	3.051757812500000000e-05
	Q15.16:	1.525878906250000000e-05
	Q14.17:	7.629394531250000000e-06
	Q13.18:	3.814697265625000000e-06
	Q12.19:	1.907348632812500000e-06
	Q11.20:	9.536743164062500000e-07
	Q10.21:	4.768371582031250000e-07
	Q9.22:	2.384185791015625000e-07
	Q8.23:	1.192092895507812500e-07
	Q7.24:	5.960464477539062500e-08
	Q6.25:	2.980232238769531250e-08
	Q5.26:	1.490116119384765625e-08
	Q4.27:	7.450580596923828125e-09
	Q3.28:	3.725290298461914062e-09
	Q2.29:	1.862645149230957031e-09
	Q1.30:	9.313225746154785156e-10
	Q0.31:	4.656612873077392578e-10
  And the exact covering ranges are;
	Q30.1:	[-1.073741824000000000e+09, 1.073741823500000000e+09]
	Q29.2:	[-5.368709120000000000e+08, 5.368709117500000000e+08]
	Q28.3:	[-2.684354560000000000e+08, 2.684354558750000000e+08]
	Q27.4:	[-1.342177280000000000e+08, 1.342177279375000000e+08]
	Q26.5:	[-6.710886400000000000e+07, 6.710886396875000000e+07]
	Q25.6:	[-3.355443200000000000e+07, 3.355443198437500000e+07]
	Q24.7:	[-1.677721600000000000e+07, 1.677721599218750000e+07]
	Q23.8:	[-8.388608000000000000e+06, 8.388607996093750000e+06]
	Q22.9:	[-4.194304000000000000e+06, 4.194303998046875000e+06]
	Q21.10:	[-2.097152000000000000e+06, 2.097151999023437500e+06]
	Q20.11:	[-1.048576000000000000e+06, 1.048575999511718750e+06]
	Q19.12:	[-5.242880000000000000e+05, 5.242879997558593750e+05]
	Q18.13:	[-2.621440000000000000e+05, 2.621439998779296875e+05]
	Q17.14:	[-1.310720000000000000e+05, 1.310719999389648438e+05]
	Q16.15:	[-6.553600000000000000e+04, 6.553599996948242188e+04]
	Q15.16:	[-3.276800000000000000e+04, 3.276799998474121094e+04]
	Q14.17:	[-1.638400000000000000e+04, 1.638399999237060547e+04]
	Q13.18:	[-8.192000000000000000e+03, 8.191999996185302734e+03]
	Q12.19:	[-4.096000000000000000e+03, 4.095999998092651367e+03]
	Q11.20:	[-2.048000000000000000e+03, 2.047999999046325684e+03]
	Q10.21:	[-1.024000000000000000e+03, 1.023999999523162842e+03]
	Q9.22:	[-5.120000000000000000e+02, 5.119999997615814209e+02]
	Q8.23:	[-2.560000000000000000e+02, 2.559999998807907104e+02]
	Q7.24:	[-1.280000000000000000e+02, 1.279999999403953552e+02]
	Q6.25:	[-6.400000000000000000e+01, 6.399999997019767761e+01]
	Q5.26:	[-3.200000000000000000e+01, 3.199999998509883881e+01]
	Q4.27:	[-1.600000000000000000e+01, 1.599999999254941940e+01]
	Q3.28:	[-8.000000000000000000e+00, 7.999999996274709702e+00]
	Q2.29:	[-4.000000000000000000e+00, 3.999999998137354851e+00]
	Q1.30:	[-2.000000000000000000e+00, 1.999999999068677425e+00]
	Q0.31:	[-1.000000000000000000e+00, 9.999999995343387127e-01]

# APIs - 16bit Q format
  // Return the Q format with the range larger than given range
  fixed16_qformat_t fixed16_get_qformat_covering_range(double fmin, double fmax);
  // Return the Q format with the unit resolution finer than given epsilon
  fixed16_qformat_t fixed16_get_qformat_covering_resolution(double epsilon);
  // Generate the unit resolutions of Q16 format in float-typed container
  void fixed16_generate_resolutions_in_float(void);
  // Generate the covering ranges of Q16 format in float-typed container
  void fixed16_generate_ranges_in_float(void);
  // Generate the unit resolutions of Q16 format in double-typed container
  void fixed16_generate_resolutions_in_double(void);
  // Generate the covering ranges of Q16 format in double-typed container
  void fixed16_generate_ranges_in_double(void);
  // Conversion between 16bit Q formats
  fixed16_t fixed16_convert(fixed16_t fix16, fixed16_qformat_t q1, fixed16_qformat_t q2);
  // Conversion between 16bit Q format, and standard c-type
  static inline fixed16_t uint8_to_fixed16(uint8_t v, fixed16_qformat_t q) { return (fixed16_t)v << q; }
  static inline fixed16_t int8_to_fixed16(int8_t v, fixed16_qformat_t q) { return (fixed16_t)v << q; }
  static inline fixed16_t uint16_to_fixed16(uint16_t v, fixed16_qformat_t q) { return (fixed16_t)v << q; }
  static inline fixed16_t int16_to_fixed16(int16_t v, fixed16_qformat_t q) { return (fixed16_t)v << q; }
  static inline fixed16_t uint32_to_fixed16(uint32_t v, fixed16_qformat_t q) { return (fixed16_t)v << q; }
  static inline fixed16_t int32_to_fixed16(int32_t v, fixed16_qformat_t q) { return (fixed16_t)v << q; }
  static inline fixed16_t float_to_fixed16(float v, fixed16_qformat_t q) { return (fixed16_t)(v * (1UL << q)); }
  static inline fixed16_t double_to_fixed16(double v, fixed16_qformat_t q) { return (fixed16_t)(v * (1UL << q)); }
  static inline uint8_t fixed16_to_uint8(fixed16_t fix16, fixed16_qformat_t q) { return (uint8_t)(fix16 >> q); }
  static inline int8_t fixed16_to_int8(fixed16_t fix16, fixed16_qformat_t q) { return (int8_t)(fix16 >> q); }
  static inline uint16_t fixed16_to_uint16(fixed16_t fix16, fixed16_qformat_t q) { return (uint16_t)(fix16 >> q); }
  static inline int16_t fixed16_to_int16(fixed16_t fix16, fixed16_qformat_t q) { return (int16_t)(fix16 >> q); }
  static inline uint32_t fixed16_to_uint32(fixed16_t fix16, fixed16_qformat_t q) { return (uint32_t)(fix16 >> q); }
  static inline int32_t fixed16_to_int32(fixed16_t fix16, fixed16_qformat_t q) { return (int32_t)(fix16 >> q); }
  static inline float fixed16_to_float(fixed16_t fix16, fixed16_qformat_t q) { return (float)fix16 / (1UL << q); }
  static inline double fixed16_to_double(fixed16_t fix16, fixed16_qformat_t q) { return (double)fix16 / (1UL << q); }
  // Arithmetic operations of 16bit Q Format
  static inline fixed16_t fixed16_add(fixed16_t a, fixed16_t b) { fixed16_t c; c = a + b; return c; }
  fixed16_t fixed16_add_with_trim(fixed16_t a, fixed16_t b);
  static inline fixed16_t fixed16_subtract(fixed16_t a, fixed16_t b) { fixed16_t c; c = a - b; return c; }
  fixed16_t fixed16_subtract_with_trim(fixed16_t a, fixed16_t b);
  fixed16_t fixed16_multiply(fixed16_t a, fixed16_t b, fixed16_qformat_t q);
  fixed16_t fixed16_divide(fixed16_t a, fixed16_t b, fixed16_qformat_t q);

# APIs - 32bit Q format
  // Return the Q format with the range larger than given range
  fixed32_qformat_t fixed32_get_qformat_covering_range(double fmin, double fmax);
  // Return the Q format with the unit resolution finer than given epsilon
  fixed32_qformat_t fixed32_get_qformat_covering_resolution(double epsilon);
  // Generate the unit resolutions of Q32 format in float-typed container
  void fixed32_generate_resolutions_in_float(void);
  // Generate the covering ranges of Q32 format in float-typed container
  void fixed32_generate_ranges_in_float(void);
  // Generate the unit resolutions of Q32 format in double-typed container
  void fixed32_generate_resolutions_in_double(void);
  // Generate the covering ranges of Q32 format in double-typed container
  void fixed32_generate_ranges_in_double(void);
  // Conversion between 32bit Q formats
  fixed32_t fixed32_convert(fixed32_t fix32, fixed32_qformat_t q1, fixed32_qformat_t q2);
  // Conversion between 32bit Q format, and standard c-type
  static inline fixed32_t uint8_to_fixed32(uint8_t v, fixed32_qformat_t q) { return (fixed32_t)v << q; }
  static inline fixed32_t int8_to_fixed32(int8_t v, fixed32_qformat_t q) { return (fixed32_t)v << q; }
  static inline fixed32_t uint16_to_fixed32(uint16_t v, fixed32_qformat_t q) { return (fixed32_t)v << q; }
  static inline fixed32_t int16_to_fixed32(int16_t v, fixed32_qformat_t q) { return (fixed32_t)v << q; }
  static inline fixed32_t uint32_to_fixed32(uint32_t v, fixed32_qformat_t q) { return (fixed32_t)v << q; }
  static inline fixed32_t int32_to_fixed32(int32_t v, fixed32_qformat_t q) { return (fixed32_t)v << q; }
  static inline fixed32_t float_to_fixed32(float v, fixed32_qformat_t q) { return (fixed32_t)(v * (1UL << q)); }
  static inline fixed32_t double_to_fixed32(double v, fixed32_qformat_t q) { return (fixed32_t)(v * (1UL << q)); }
  static inline uint8_t fixed32_to_uint8(fixed32_t fix32, fixed32_qformat_t q) { return (uint8_t)(fix32 >> q); }
  static inline int8_t fixed32_to_int8(fixed32_t fix32, fixed32_qformat_t q) { return (int8_t)(fix32 >> q); }
  static inline uint16_t fixed32_to_uint16(fixed32_t fix32, fixed32_qformat_t q) { return (uint16_t)(fix32 >> q); }
  static inline int16_t fixed32_to_int16(fixed32_t fix32, fixed32_qformat_t q) { return (int16_t)(fix32 >> q); }
  static inline uint32_t fixed32_to_uint32(fixed32_t fix32, fixed32_qformat_t q) { return (uint32_t)(fix32 >> q); }
  static inline int32_t fixed32_to_int32(fixed32_t fix32, fixed32_qformat_t q) { return (int32_t)(fix32 >> q); }
  static inline float fixed32_to_float(fixed32_t fix32, fixed32_qformat_t q) { return (float)fix32 / (1UL << q); }
  static inline double fixed32_to_double(fixed32_t fix32, fixed32_qformat_t q) { return (double)fix32 / (1UL << q); }
  // Arithmetic operations of 32bit Q Format
  static inline fixed32_t fixed32_add(fixed32_t a, fixed32_t b) { fixed32_t c; c = a + b; return c; }
  fixed32_t fixed32_add_with_trim(fixed32_t a, fixed32_t b);
  static inline fixed32_t fixed32_subtract(fixed32_t a, fixed32_t b) { fixed32_t c; c = a - b; return c; }
  fixed32_t fixed32_subtract_with_trim(fixed32_t a, fixed32_t b);
  fixed32_t fixed32_multiply(fixed32_t a, fixed32_t b, fixed32_qformat_t q);
  fixed32_t fixed32_divide(fixed32_t a, fixed32_t b, fixed32_qformat_t q);

# Additional feature 
CORDIC-based 
