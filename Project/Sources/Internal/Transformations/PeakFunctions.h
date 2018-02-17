#pragma once

#include "TransformationsLibPrivate.h"
#include <math.h>
#include <complex>
#include "Cerf.h"
#include "stdlib.h"

namespace DataAnalysis {
	namespace Transformations {

		template <class BaseType = double> class LorentzFunction : public IFunction<BaseType> {

		public:

			LorentzFunction() {
				mType = FT_MODEL_PEAKS;
			}

			void Initialize(__in const double *params) {
				mParams = params;
				mInitialized = true;
			}

			virtual inline void Apply(__in const BaseType &in, __out BaseType &out) const {
				if (mParams != nullptr) {
					//out += Lorentz(in);
					double v = in;
					double t0 = mParams[6] / 2;
					double v0 = mParams[3];
					double delta0 = mParams[8];

					//calculate divisor
					double divisor = pow(v - (v0 + delta0), 2) + pow(t0, 2);

					//calculate first multiplier
					double multiplier = 1 / M_PI;

					//return multiplier *	(abs(t0) / divisor);
					out = multiplier *	(abs(t0) / divisor);
				}
			}

		protected:

			const double *mParams;

		private:

		};
		template <class BaseType = double> class GaussFunction : public IFunction<BaseType> {

		public:

			GaussFunction() {
				mType = FT_MODEL_PEAKS;
			}

			void Initialize(__in const double *params) {
				mParams = params;
				mInitialized = true;
			}

			virtual inline void Apply(__in const BaseType &in, __out BaseType &out) const {
				if (mParams != nullptr) {
					double v = in;
					double v0 = mParams[3];
					double delta0 = mParams[8];
					double t0 = mParams[7] / 2;

					//calculate part in bracket
					double zatvorka = -log(2) * (pow(v - (v0 + delta0), 2) / pow(t0, 2));

					//calculate first multiplier
					double prvy = 1 / t0;

					//calculate second multiplier
					double druhy = sqrt(log(2) / M_PI);

					double expe = exp(zatvorka);
					out = prvy * druhy * expe;
				}
			}

		private:
			const double *mParams;

		};

		template <class BaseType = double> class VoigtFunction : public IFunction<BaseType> {

		public:

			VoigtFunction() {
				mType = FT_MODEL_PEAKS;
			}

			void Initialize(__in const double *params) {
				mParams = params;
				mInitialized = true;
			}

			virtual void Apply(__in const BaseType &in, __out BaseType &out) const {
				if (mParams != nullptr) {
					//out += Voigt(in);
					double v = in;
					static const std::complex<double> i(0.0, 1.0);
					double w0 = mParams[6];
					double td = w0 / 2;
					double v0 = mParams[3];
					double delta0 = mParams[8];


					//counting z
					std::complex<double> z = log(2) * ((w0 + i*(v0 + delta0 - v)) / td);

					//counting first multiplier
					double first = 1 / abs(td);

					//counting second multiplier
					double second = sqrt(log(2) / M_PI);

					//Counting cerf funtion
					std::complex<double> Mycerf = Cerf::erfc(-z);

					//counting third multiplier
					std::complex<double> third = pow(M_E, pow(-z, 2)) * Mycerf;

					//return first * second * third;
					out = first * second * third.real();
				}
			}

		protected:

			const double *mParams;

		private:

		};

	}
}
