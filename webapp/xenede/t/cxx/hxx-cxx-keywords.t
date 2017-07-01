%########################################################################
%# Copyright (c) 1988-2017 $organization$
%#
%# This software is provided by the author and contributors ``as is'' 
%# and any express or implied warranties, including, but not limited to, 
%# the implied warranties of merchantability and fitness for a particular 
%# purpose are disclaimed. In no event shall the author or contributors 
%# be liable for any direct, indirect, incidental, special, exemplary, 
%# or consequential damages (including, but not limited to, procurement 
%# of substitute goods or services; loss of use, data, or profits; or 
%# business interruption) however caused and on any theory of liability, 
%# whether in contract, strict liability, or tort (including negligence 
%# or otherwise) arising in any way out of the use of this software, 
%# even if advised of the possibility of such damage.
%#
%#   File: hxx-cxx-keywords.t
%#
%# Author: $author$
%#   Date: 6/30/2017
%########################################################################
%with(%
%_#import_,%(%else-then(%_#import_%,%(%xx_%#import%_xx%)%)%)%,%
%_@class_,%(%else-then(%_@class_%,%(%xx_%@class%_xx%)%)%)%,%
%_@interface_,%(%else-then(%_@interface_%,%(%xx_%@interface%_xx%)%)%)%,%
%_@implementation_,%(%else-then(%_@implementation_%,%(%xx_%@implementation%_xx%)%)%)%,%
%_@protocol_,%(%else-then(%_@protocol_%,%(%xx_%@protocol%_xx%)%)%)%,%
%_@property_,%(%else-then(%_@property_%,%(%xx_%@property%_xx%)%)%)%,%
%_@end_,%(%else-then(%_@end_%,%(%xx_%@end%_xx%)%)%)%,%
%_#include_,%(%else-then(%_#include_%,%(%kk_%#include%_kk%)%)%)%,%
%_#if_,%(%else-then(%_#if_%,%(%kk_%#if%_kk%)%)%)%,%
%_#ifdef_,%(%else-then(%_#ifdef_%,%(%kk_%#ifdef%_kk%)%)%)%,%
%_#ifndef_,%(%else-then(%_#ifndef_%,%(%kk_%#ifndef%_kk%)%)%)%,%
%_#elif_,%(%else-then(%_#elif_%,%(%kk_%#elif%_kk%)%)%)%,%
%_#else_,%(%else-then(%_#else_%,%(%kk_%#else%_kk%)%)%)%,%
%_#endif_,%(%else-then(%_#endif_%,%(%kk_%#endif%_kk%)%)%)%,%
%_#define_,%(%else-then(%_#define_%,%(%kk_%#define%_kk%)%)%)%,%
%_#undef_,%(%else-then(%_#undef_%,%(%kk_%#undef%_kk%)%)%)%,%
%_#pragma_,%(%else-then(%_#pragma_%,%(%kk_%#pragma%_kk%)%)%)%,%
%_defined_,%(%else-then(%_defined_%,%(%kk_%defined%_kk%)%)%)%,%
%__attribute__,%(%else-then(%__attribute__%,%(%kk_%__attribute__%_kk%)%)%)%,%
%_namespace_,%(%else-then(%_namespace_%,%(%kk_%namespace%_kk%)%)%)%,%
%_template_,%(%else-then(%_template_%,%(%kk_%template%_kk%)%)%)%,%
%_typedef_,%(%else-then(%_typedef_%,%(%kk_%typedef%_kk%)%)%)%,%
%_enum_,%(%else-then(%_enum_%,%(%kk_%enum%_kk%)%)%)%,%
%_struct_,%(%else-then(%_struct_%,%(%kk_%struct%_kk%)%)%)%,%
%_union_,%(%else-then(%_union_%,%(%kk_%union%_kk%)%)%)%,%
%_class_,%(%else-then(%_class_%,%(%kk_%class%_kk%)%)%)%,%
%_public_,%(%else-then(%_public_%,%(%kk_%public%_kk%)%)%)%,%
%_protected_,%(%else-then(%_protected_%,%(%kk_%protected%_kk%)%)%)%,%
%_private_,%(%else-then(%_private_%,%(%kk_%private%_kk%)%)%)%,%
%_virtual_,%(%else-then(%_virtual_%,%(%kk_%virtual%_kk%)%)%)%,%
%_volitile_,%(%else-then(%_volitile_%,%(%kk_%volitile%_kk%)%)%)%,%
%_extern_,%(%else-then(%_extern_%,%(%kk_%extern%_kk%)%)%)%,%
%_static_,%(%else-then(%_static_%,%(%kk_%static%_kk%)%)%)%,%
%_const_,%(%else-then(%_const_%,%(%kk_%const%_kk%)%)%)%,%
%_signed_,%(%else-then(%_signed_%,%(%kk_%signed%_kk%)%)%)%,%
%_unsigned_,%(%else-then(%_unsigned_%,%(%kk_%unsigned%_kk%)%)%)%,%
%_long_,%(%else-then(%_long_%,%(%kk_%long%_kk%)%)%)%,%
%_short_,%(%else-then(%_short_%,%(%kk_%short%_kk%)%)%)%,%
%_double_,%(%else-then(%_double_%,%(%kk_%double%_kk%)%)%)%,%
%_float_,%(%else-then(%_float_%,%(%kk_%float%_kk%)%)%)%,%
%_int_,%(%else-then(%_int_%,%(%kk_%int%_kk%)%)%)%,%
%_char_,%(%else-then(%_char_%,%(%kk_%char%_kk%)%)%)%,%
%_bool_,%(%else-then(%_bool_%,%(%kk_%bool%_kk%)%)%)%,%
%_true_,%(%else-then(%_true_%,%(%kk_%true%_kk%)%)%)%,%
%_false_,%(%else-then(%_false_%,%(%kk_%false%_kk%)%)%)%,%
%_return_,%(%else-then(%_return_%,%(%kk_%return%_kk%)%)%)%,%
%_switch_,%(%else-then(%_switch_%,%(%kk_%switch%_kk%)%)%)%,%
%_case_,%(%else-then(%_case_%,%(%kk_%case%_kk%)%)%)%,%
%_break_,%(%else-then(%_break_%,%(%kk_%break%_kk%)%)%)%,%
%_default_,%(%else-then(%_default_%,%(%kk_%default%_kk%)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%keywords_fileinclude,%(%keywords_includefile%)%,%
%keywords_includefile,%()%,%
%%(%
%%include(%keywords_fileinclude%)%%
%)%)%