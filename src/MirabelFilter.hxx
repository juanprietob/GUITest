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

template< class TImage>
void itk::MirabelFilter<TImage>::GenerateData()
{
    typename TImage::ConstPointer input = this->GetInput();
    typename TImage::Pointer output = this->GetOutput();


    // iterators definitions
    typedef ShapedNeighborhoodIterator<TImage> NeighborhoodIteratorType;
    typedef ImageRegionIterator<TImage> IteratorType;

    // Create the iterators
    typename NeighborhoodIteratorType::RadiusType radius;
    radius.Fill(this->kernelSize);
    NeighborhoodIteratorType it(radius,input,input->GetRequestedRegion());
    this->AllocateOutputs();
    IteratorType out(output,output->GetRequestedRegion());

    // Neighborhood offsets
    for(int i=-kernelSize;i<=kernelSize;++i)
    {
        for(int j=-kernelSize;j<=kernelSize;++j)
        {
            typename NeighborhoodIteratorType::OffsetType offset = {{i,j}};
            it.ActivateOffset(offset);
        }
    }

    //
    float sum=0;
    for(it.GoToBegin();!it.IsAtEnd();++it)
    {
        ++out;
        sum=0.0;
        typename NeighborhoodIteratorType::ConstIterator ci = it.Begin();
        while( !ci.IsAtEnd() )
        {
            sum += ci.Get();
            ++ci;
        }
        sum /= (2.0*this->kernelSize+1)*(2.0*this->kernelSize+1);
        out.Set(sum);
    }
}
template< class TImage>
void itk::MirabelFilter<TImage>::SetKernelSize(int kernelSizeParam)
{
    kernelSize=kernelSizeParam;
}

#endif
