package io.adaptivecards.renderer.readonly;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapShader;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Shader;
import android.support.v4.app.FragmentManager;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;

import io.adaptivecards.objectmodel.ContainerStyle;
import io.adaptivecards.objectmodel.HeightType;
import io.adaptivecards.renderer.InnerImageLoaderAsync;
import io.adaptivecards.renderer.RenderedAdaptiveCard;
import io.adaptivecards.renderer.Util;
import io.adaptivecards.renderer.action.ActionElementRenderer;
import io.adaptivecards.renderer.actionhandler.ICardActionHandler;
import io.adaptivecards.objectmodel.BaseCardElement;
import io.adaptivecards.objectmodel.HorizontalAlignment;
import io.adaptivecards.objectmodel.HostConfig;
import io.adaptivecards.objectmodel.Image;
import io.adaptivecards.objectmodel.ImageSize;
import io.adaptivecards.objectmodel.ImageSizesConfig;
import io.adaptivecards.objectmodel.ImageStyle;
import io.adaptivecards.renderer.BaseCardElementRenderer;
import io.adaptivecards.renderer.layout.HorizontalFlowLayout;

public class ImageRenderer extends BaseCardElementRenderer
{
    protected ImageRenderer()
    {
    }

    public static ImageRenderer getInstance()
    {
        if (s_instance == null)
        {
            s_instance = new ImageRenderer();
        }

        return s_instance;
    }

    private class ImageRendererImageLoaderAsync extends InnerImageLoaderAsync
    {
        ImageRendererImageLoaderAsync(RenderedAdaptiveCard renderedCard, ImageView imageView, String imageBaseUrl, ImageStyle imageStyle)
        {
            super(renderedCard, imageView, imageBaseUrl);
            m_imageStyle = imageStyle;
        }

        @Override
        protected Bitmap styleBitmap(Bitmap bitmap)
        {
            if (bitmap != null && m_imageStyle == ImageStyle.Person)
            {
                Bitmap circleBitmap = Bitmap.createBitmap(bitmap.getWidth(), bitmap.getHeight(), Bitmap.Config.ARGB_8888);
                BitmapShader shader = new BitmapShader(bitmap,  Shader.TileMode.CLAMP, Shader.TileMode.CLAMP);
                Paint paint = new Paint();
                paint.setShader(shader);
                Canvas c = new Canvas(circleBitmap);
                c.drawCircle(bitmap.getWidth()/2, bitmap.getHeight()/2, bitmap.getWidth()/2, paint);
                bitmap = circleBitmap;
            }
            return bitmap;
    }

        @Override
        protected void renderBitmap(Bitmap bitmap)
        {
            ImageView view = (ImageView) m_view ;
            view.setImageBitmap(bitmap);
        }

        private ImageStyle m_imageStyle;
    }

    private static void setImageSize(Context context, ImageView imageView, ImageSize imageSize, ImageSizesConfig imageSizesConfig) {
        imageView.setScaleType(ImageView.ScaleType.CENTER);
        if (imageSize == ImageSize.Stretch) {
            //ImageView must match parent for stretch to work
            imageView.setLayoutParams(new LinearLayout.LayoutParams(RelativeLayout.LayoutParams.MATCH_PARENT, RelativeLayout.LayoutParams.MATCH_PARENT));
            imageView.setScaleType(ImageView.ScaleType.CENTER_INSIDE);
        } else if (imageSize == ImageSize.Small) {
            imageView.setMaxWidth(Util.dpToPixels(context, imageSizesConfig.getSmallSize()));
        } else if (imageSize == ImageSize.Medium) {
            imageView.setMaxWidth(Util.dpToPixels(context, imageSizesConfig.getMediumSize()));
        } else if (imageSize == ImageSize.Large) {
            imageView.setMaxWidth(Util.dpToPixels(context, imageSizesConfig.getLargeSize()));
        } else if (imageSize != ImageSize.Auto && imageSize != ImageSize.None){
            throw new IllegalArgumentException("Unknown image size: " + imageSize.toString());
        }

        imageView.setAdjustViewBounds(true);
    }

    @Override
    public View render(
            RenderedAdaptiveCard renderedCard,
            Context context,
            FragmentManager fragmentManager,
            ViewGroup viewGroup,
            BaseCardElement baseCardElement,
            ICardActionHandler cardActionHandler,
            HostConfig hostConfig,
            ContainerStyle containerStyle)
    {
        Image image;
        if (baseCardElement instanceof Image)
        {
            image = (Image) baseCardElement;
        }
        else if ((image = Image.dynamic_cast(baseCardElement)) == null)
        {
            throw new InternalError("Unable to convert BaseCardElement to Image object model.");
        }

        ImageView imageView = new ImageView(context);
        imageView.setTag(image);
        ImageRendererImageLoaderAsync imageLoaderAsync = new ImageRendererImageLoaderAsync(renderedCard, imageView, hostConfig.getImageBaseUrl(), image.GetImageStyle());
        imageLoaderAsync.execute(image.GetUrl());

        LinearLayout.LayoutParams layoutParams;
        if (image.GetImageSize() == ImageSize.Stretch)
        {
            //ImageView must match parent for stretch to work
            if( image.GetHeight() == HeightType.Stretch )
            {
                layoutParams = new LinearLayout.LayoutParams(RelativeLayout.LayoutParams.MATCH_PARENT, RelativeLayout.LayoutParams.MATCH_PARENT, 1);
            }
            else
            {
                layoutParams = new LinearLayout.LayoutParams(RelativeLayout.LayoutParams.MATCH_PARENT, RelativeLayout.LayoutParams.WRAP_CONTENT);
            }
        }
        else
        {
            if( image.GetHeight() == HeightType.Stretch )
            {
                layoutParams = new LinearLayout.LayoutParams(RelativeLayout.LayoutParams.WRAP_CONTENT, RelativeLayout.LayoutParams.MATCH_PARENT, 1);
            }
            else
            {
                layoutParams = new LinearLayout.LayoutParams(RelativeLayout.LayoutParams.WRAP_CONTENT, RelativeLayout.LayoutParams.WRAP_CONTENT);
            }
        }

        HorizontalAlignment horizontalAlignment = image.GetHorizontalAlignment();
        if (horizontalAlignment == HorizontalAlignment.Right)
        {
            layoutParams.gravity = Gravity.RIGHT;
        }
        else if (horizontalAlignment == HorizontalAlignment.Center)
        {
            layoutParams.gravity = Gravity.CENTER_HORIZONTAL;
        }

        if (image.GetSelectAction() != null)
        {
            imageView.setClickable(true);
            imageView.setOnClickListener(new ActionElementRenderer.ButtonOnClickListener(renderedCard, image.GetSelectAction(), cardActionHandler));
        }

        //set horizontalAlignment
        imageView.setLayoutParams(layoutParams);

        setImageSize(context, imageView, image.GetImageSize(), hostConfig.getImageSizes());
        setSpacingAndSeparator(context, viewGroup, image.GetSpacing(), image.GetSeparator(), hostConfig, !(viewGroup instanceof HorizontalFlowLayout) /* horizontal line */);

        viewGroup.addView(imageView);
        return imageView;
    }

    private static ImageRenderer s_instance = null;
}
