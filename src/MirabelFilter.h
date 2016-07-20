#ifndef MIRABELFILTER_HXX
#define MIRABELFILTER_HXX

#include "itkObjectFactory.h"
#include "itkImageRegionIterator.h"
#include "itkShapedNeighborhoodIterator.h"
#include "itkImageToImageFilter.h"


namespace itk
{
    template< class TImage>
    class MirabelFilter:public ImageToImageFilter< TImage, TImage >
    {
    public:
        /** Standard class typedefs. */
        typedef MirabelFilter             Self;
        typedef ImageToImageFilter< TImage, TImage > Superclass;
        typedef SmartPointer< Self >        Pointer;
        void SetKernelSize(int kernelSizeParam);

        /** Method for creation through the object factory. */
        itkNewMacro(Self)

        /** Run-time type information (and related methods). */
        itkTypeMacro(ImageFilter, ImageToImageFilter)

    protected:
        MirabelFilter(){}
        ~MirabelFilter(){}
        virtual void GenerateData();

    private:
        int kernelSize;

    };
}

#ifndef ITK_MANUAL_INSTANTIATION
#include "MirabelFilter.hxx"
#endif

#endif