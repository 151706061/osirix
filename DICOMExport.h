/*=========================================================================
  Program:   OsiriX

  Copyright (c) OsiriX Team
  All rights reserved.
  Distributed under GNU - GPL
  
  See http://www.osirix-viewer.com/copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.
=========================================================================*/



#import <Cocoa/Cocoa.h>

@class DCMObject;
@class DCMExportPlugin;

/** \brief Export image as DICOM  */
@interface DICOMExport : NSObject
{
		NSString			*dcmSourcePath;
		DCMObject			*dcmDst;
		
		// Raw data support
		unsigned char		*data;
		long				width, height, spp, bps;
		BOOL				isSigned, modalityAsSource;
		int					offset;
		
		// NSImage support
		NSImage				*image;
		NSBitmapImageRep	*imageRepresentation;
		unsigned char		*imageData;
		BOOL				freeImageData;
		
		int					exportInstanceNumber, exportSeriesNumber;
		NSString			*exportSeriesUID;
		NSString			*exportSeriesDescription;
		
		long				ww, wl;
		float				spacingX, spacingY, slope;
		float				sliceThickness;
		float				sliceInterval;
		float				orientation[ 6];
		float				position[ 3];
		float				slicePosition;
}

// Is this DCM file based on another DCM file?
- (void) setSourceFile:(NSString*) isource;

// Set Pixel Data from a raw source
- (long) setPixelData:		(unsigned char*) idata
		samplesPerPixel:	(long) ispp
		bitsPerSample:		(long) ibps
		width:				(long) iwidth
		height:				(long) iheight;

- (long) setPixelData:		(unsigned char*) idata
		samplePerPixel:		(long) ispp
		bitsPerPixel:		(long) ibps // This is INCORRECT - backward compatibility
		width:				(long) iwidth
		height:				(long) iheight;

- (void) setSigned: (BOOL) s;
- (void) setOffset: (int) o;

// Set Pixel Data from a NSImage
- (long) setPixelNSImage:	(NSImage*) iimage;

// Write the image data
- (NSString*) writeDCMFile: (NSString*) dstPath;
- (NSString*) writeDCMFile: (NSString*) dstPath withExportDCM:(DCMExportPlugin*) dcmExport;
- (void) setModalityAsSource: (BOOL) v;
- (NSString*) seriesDescription;
- (void) setSeriesDescription: (NSString*) desc;
- (void) setSeriesNumber: (long) no;
- (void) setDefaultWWWL: (long) ww :(long) wl;
- (void) setSlope: (float) s;
- (void) setPixelSpacing: (float) x :(float) y;
- (void) setSliceThickness: (double) t;
- (void) setOrientation: (float*) o;
- (void) setPosition: (float*) p;
- (void) setSlicePosition: (float) p;
- (NSString*) SOPInstanceUID;
@end
