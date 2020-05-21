#include "convolution.h"

template<typename P>
void ApplyFilter(ImageClass<P> & img_in, ImageClass<P> & img_out) {
  
  const int width  = img_in.width;
  const int height = img_in.height;

  P * in  = img_in.pixel;
  P * out = img_out.pixel;

#pragma omp parallel for
  for (int i = 1; i < height-1; i++)
#pragma omp simd
#pragma vector nontemporal
    for (int j = 1; j < width-1; j++) {
      int val = -in[(i-1)*width + j-1] -   in[(i-1)*width + j] - in[(i-1)*width + j+1] 
	        -in[(i  )*width + j-1] + 8*in[(i  )*width + j] - in[(i  )*width + j+1] 
	        -in[(i+1)*width + j-1] -   in[(i+1)*width + j] - in[(i+1)*width + j+1];

      val = (val < 0   ? 0   : val);
      val = (val > 255 ? 255 : val);

      out[i*width + j] = val;
    }
  
}

template void ApplyFilter<float>(ImageClass<float> & img_in, ImageClass<float> & img_out);
template void ApplyFilter<png_byte>(ImageClass<png_byte> & img_in, ImageClass<png_byte> & img_out);
